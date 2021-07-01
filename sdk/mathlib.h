#include <math.h>

#if !defined(M_PI)
#define M_PI 3.14159265358979323846
#endif

#define FL_PI 3.14159265358979323846f

#define PITCH 0
#define YAW 1
#define ROLL 2

/* what the fuck */
float ATANF(float a);
float COSF(float a);
float SINF(float a);
float SQRTF(float a);
float TANF(float a);

typedef float vec_t;
typedef vec_t vec3_t[3];

void AngleVectors(const vec3_t angles, vec3_t forward, vec3_t right, vec3_t up);
void VectorMA(const vec3_t veca, float scale, const vec3_t vecb, vec3_t vecc);
void InverseRollVectorMA(const vec3_t veca, float scale, const vec3_t vecb, vec3_t vecc);

float Lerp(float a, float b, float f);
void VectorLerp(vec3_t a, vec3_t b, float f, vec3_t out);

float EaseOut(float a, float b, float f);
