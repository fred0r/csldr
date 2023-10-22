#define MAX_ELIGHTS 3

typedef struct
{
	cl_entity_t *entity;
	studiohdr_t *header;
	model_t *model;
	studio_cache_t *cache;

	// mikkotodo revisit!!!
	mat3x4_t cpy_bonetransform[128];

	int num_bodyparts;
	int bodyparts[128]; // mikkotodo alloc dynamically

	float ambientlight;
	float shadelight;
	vec3_t lightcolor;
	vec3_t lightvec;

	int forceflags;
	int options;

	int elight_num;
	float elight_pos[MAX_ELIGHTS][4];
	float elight_color[MAX_ELIGHTS][3];

	struct studio_shader_s *shader;
} studio_context_t;

void R_StudioInit(void);

void R_StudioNewFrame(void);

void R_StudioInitContext(studio_context_t *ctx, cl_entity_t *entity, model_t *model, studiohdr_t *header);
void R_StudioEntityLight(studio_context_t *ctx);
void R_StudioSetupLighting(studio_context_t *ctx, alight_t *lighting);

void R_StudioSetupModel(studio_context_t *ctx, int bodypart_index);

studio_context_t *R_StudioReserveQueuedModel(void);
void R_StudioCommitQueuedModel(studio_context_t *ctx);

void Hk_DrawNormalTriangles(void);
void Hk_DrawTransparentTriangles(void);
