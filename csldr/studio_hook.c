#include "pch.h"

bool studio_gpuskin;
bool studio_fastpath;

static cvar_t *studio_fastpath_toggle;

static studiohdr_t *s_header;
static model_t *s_model;

#define FASTPATH_ENABLED (studio_fastpath && studio_fastpath_toggle->value)

static studio_context_t *current_context;
#define GET_CONTEXT() (current_context ? current_context : (current_context = R_StudioReserveQueuedModel()))

static void Hk_StudioSetHeader(void *header)
{
	IEngineStudio.StudioSetHeader(header);

	if (FASTPATH_ENABLED)
	{
		s_header = (studiohdr_t *)header;
	}
}

static void Hk_SetRenderModel(model_t *model)
{
	IEngineStudio.SetRenderModel(model);

	if (FASTPATH_ENABLED)
	{
		s_model = model;
	}
}

static model_t *last_model;

static void *Hk_Mod_Extradata(model_t *model)
{
	last_model = model;
	return IEngineStudio.Mod_Extradata(model);
}

static model_t *DeduceModel(studiohdr_t *header)
{
	assert(header);

	if (last_model->cache.data == header)
		return last_model;

	Plat_Error("Could not find model for header %s\n", header->name);
	return NULL; // never reached
}

static void Hk_StudioEntityLight(alight_t *lighting)
{
	if (FASTPATH_ENABLED)
	{
		R_StudioEntityLight(GET_CONTEXT());
	}
	else
	{
		IEngineStudio.StudioEntityLight(lighting);
	}
}

static void Hk_StudioSetupLighting(alight_t *lighting)
{
	if (FASTPATH_ENABLED)
	{
		if (!s_model || (s_model->cache.data && (s_model->cache.data != s_header)))
		{
			// this happens with player weapon models... Mod_Extradata is called right
			// before this so we should be able to get the model pointer from there
			s_model = DeduceModel(s_header);
		}

		assert(s_model);
		assert(s_header);

		studio_context_t *context = GET_CONTEXT();

		R_StudioInitContext(context, IEngineStudio.GetCurrentEntity(), s_model, s_header);
		R_StudioSetupLighting(context, lighting);
	}
	else
	{
		IEngineStudio.StudioSetupLighting(lighting);
	}
}

void Hk_StudioSetupModel(int bodypart, void **ppbodypart, void **ppsubmodel)
{
	IEngineStudio.StudioSetupModel(bodypart, ppbodypart, ppsubmodel);

	if (FASTPATH_ENABLED)
	{
		R_StudioSetupModel(GET_CONTEXT(), bodypart);
	}
}

static void Hk_StudioDrawPoints(void)
{
	if (FASTPATH_ENABLED)
	{
		// nothing
	}
	else
	{
		IEngineStudio.StudioDrawPoints();
	}
}

static void Hk_StudioDrawHulls(void)
{
	if (FASTPATH_ENABLED)
	{
		// not implmeneted for fast path
	}
	else
	{
		IEngineStudio.StudioDrawHulls();
	}
}

static void Hk_StudioDrawAbsBBox(void)
{
	if (FASTPATH_ENABLED)
	{
		// not implmeneted for fast path
	}
	else
	{
		IEngineStudio.StudioDrawAbsBBox();
	}
}

static void Hk_StudioDrawBones(void)
{
	if (FASTPATH_ENABLED)
	{
		// not implmeneted for fast path
	}
	else
	{
		IEngineStudio.StudioDrawBones();
	}
}

static void Hk_SetupRenderer(int rendermode)
{
	if (FASTPATH_ENABLED)
	{
		// nothing
	}
	else
	{
		IEngineStudio.SetupRenderer(rendermode);
	}
}

static void Hk_RestoreRenderer(void)
{
	if (FASTPATH_ENABLED)
	{
		R_StudioCommitQueuedModel(GET_CONTEXT());
		current_context = NULL;
	}
	else
	{
		IEngineStudio.RestoreRenderer();
	}
}

static void StudioInfo_f(void)
{
	gEngfuncs.Con_Printf("OpenGL version: %s\n", glGetString(GL_VERSION));
	gEngfuncs.Con_Printf("GL_ARB_uniform_buffer_object: %s\n", GLAD_GL_ARB_uniform_buffer_object ? "available" : "not available");
	gEngfuncs.Con_Printf("Fast path: %s\n", studio_fastpath ? "available" : "not available");
	gEngfuncs.Con_Printf("GPU skinning: %s\n", studio_gpuskin ? "enabled" : "disabled");
	
	int num_models, max_models;
	StudioCacheStats(&num_models, &max_models);
	gEngfuncs.Con_Printf("Models cached: %d / %d\n", num_models, max_models);

	size_t used, size;
	Mem_GetInfo(&used, &size);
	double mb_used = used * (1.0 / 1024.0 / 1024.0);
	double mb_size = size * (1.0 / 1024.0 / 1024.0);
	gEngfuncs.Con_Printf("Memory usage: %.3f MB / %.3f MB\n", mb_used, mb_size);
}

void HookEngineStudio(engine_studio_api_t *studio)
{
	// no one uses software or d3d renderers
	if (studio->IsHardware() != 1)
		Plat_Error("Software and D3D modes are not supported\n");

	// init opengl now that we know we're not using sw or d3d
	if (!gladLoadGL())
		Plat_Error("Could not initialize OpenGL\n");

	// see if we can do fast path
	studio_fastpath = (GLAD_GL_VERSION_2_0) ? true : false;

	// see if we can do gpu skinning
	studio_gpuskin = (GLAD_GL_VERSION_2_1 && GLAD_GL_ARB_uniform_buffer_object);
	assert(studio_gpuskin); // wtf

	gEngfuncs.pfnAddCommand("studio_info", StudioInfo_f);

	// mikkotodo fix this properly
	studio->StudioSetupModel = My_StudioSetupModel; // reroute for bodygroup changing

	if (studio_fastpath)
	{
		studio->StudioSetHeader = Hk_StudioSetHeader;
		studio->Mod_Extradata = Hk_Mod_Extradata;
		studio->SetRenderModel = Hk_SetRenderModel;
		studio->StudioEntityLight = Hk_StudioEntityLight;
		studio->StudioSetupLighting = Hk_StudioSetupLighting;
		studio->StudioDrawPoints = Hk_StudioDrawPoints;
		studio->StudioDrawHulls = Hk_StudioDrawHulls;
		studio->StudioDrawAbsBBox = Hk_StudioDrawAbsBBox;
		studio->StudioDrawBones = Hk_StudioDrawBones;
		studio->SetupRenderer = Hk_SetupRenderer;
		studio->RestoreRenderer = Hk_RestoreRenderer;

		R_StudioInit();

		studio_fastpath_toggle = gEngfuncs.pfnRegisterVariable("studio_fastpath", "0", FCVAR_ARCHIVE);

		gEngfuncs.pfnAddCommand("studio_config_flush", StudioConfigFlush_f);
	}
}
