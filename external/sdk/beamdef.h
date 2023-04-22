typedef struct beam_s {
  struct beam_s* next;
  int type;
  int flags;
  Vector source;
  Vector target;
  Vector delta;
  float t;
  float freq;
  float die;
  float width;
  float amplitude;
  float r;
  float g;
  float b;
  float brightness;
  float speed;
  float frameRate;
  float frame;
  int segments;
  int startEntity;
  int endEntity;
  int modelIndex;
  int frameCount;
  model_t* pFollowModel;
  particle_t* particles;
} BEAM;