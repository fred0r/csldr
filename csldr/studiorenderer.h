extern engine_studio_api_t IEngineStudio;

bool ShouldMirrorViewmodel(cl_entity_t *vm);
void My_StudioSetupModel(int bodypart, void **ppbodypart, void **ppsubmodel);
int Hk_GetStudioModelInterface(int version, r_studio_interface_t **ppinterface, engine_studio_api_t *pstudio);
