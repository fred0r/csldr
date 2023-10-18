#if defined(GPU_SKINNING)
#extension GL_ARB_uniform_buffer_object : enable
#endif

attribute vec3 a_pos;
attribute vec3 a_normal;
attribute vec2 a_texcoord;
#if defined(GPU_SKINNING)
attribute vec2 a_bones;
#endif

varying vec2 f_texcoord;
varying vec4 f_color;

#if defined(HAVE_FOG)
varying float f_fog;
#endif

#ifdef GPU_SKINNING
layout (std140) uniform bones
{
	mat3x4 u_bones[128];
};
#endif

#if defined(GPU_SKINNING) && defined(CAN_CHROME)
uniform vec3 u_chromeorg;
uniform vec3 u_chromeright;
#endif

#if !defined(HAVE_ADDITIVE) && !defined(HAVE_GLOWHSELL)
uniform float u_ambientlight;
uniform float u_shadelight;
uniform vec3 u_lightvec;
uniform vec4 u_colormix; // 4th component is the scale with glowshell

uniform float u_lightgamma;
uniform float u_brightness;
uniform float u_invgamma;
uniform float u_g3;
#endif

#if defined(CAN_FLATSHADE)
uniform bool u_tex_flatshade;
#endif

#if defined(GPU_SKINNING) && defined(CAN_CHROME)
uniform bool u_tex_chrome;
#endif

#if defined(CAN_FULLBRIGHT)
uniform bool u_tex_fullbright;
#endif

#define MAX_ELIGHTS 3

#if defined(HAVE_ELIGHTS)
uniform vec4 u_elight_pos[MAX_ELIGHTS]; // 4th component stores radius*radius
uniform vec3 u_elight_color[MAX_ELIGHTS];
#endif

// engine's v_lambert1, doesn't change
#define LAMBERT 1.4953241

#if !defined(HAVE_ADDITIVE) && !defined(HAVE_GLOWHSELL)
float gamma_correct(float value)
{
	float f = pow(value, u_lightgamma) * max(u_brightness, 1.0);
	f = (u_g3 < f) ? ((f - u_g3) / (1.0 - u_g3) * 0.875 + 0.125) : (f / u_g3 * 0.125);
	return clamp(pow(f, u_invgamma), 0.0, 1.0);
}
#endif


#if defined(HAVE_ELIGHTS)
vec3 elight_gamma(vec3 color, vec3 elight)
{
	vec3 invgamma = vec3(u_invgamma);
	vec3 gamma = vec3(1.0 / u_invgamma);

	vec3 result = pow((pow(color, gamma) + elight), invgamma);
	return min(result, 1.0);
}
#endif

void main()
{
#if defined(GPU_SKINNING)
	mat3x4 bone = u_bones[int(a_bones.x)];

	vec3 pos_anim = vec3(
		dot(a_pos, vec3(bone[0])) + bone[0][3],
		dot(a_pos, vec3(bone[1])) + bone[1][3],
		dot(a_pos, vec3(bone[2])) + bone[2][3]);

	mat3x4 bone_normal = u_bones[int(a_bones.y)];

	vec3 normal_anim = vec3(
		dot(a_normal, vec3(bone[0])),
		dot(a_normal, vec3(bone[1])),
		dot(a_normal, vec3(bone[2])));
#else
	// already animated on the cpu
	vec3 pos_anim = a_pos;
	vec3 normal_anim = a_normal;
#endif

	normal_anim = normalize(normal_anim);

	// chrome is done on the cpu if bone information is not available
#if defined(GPU_SKINNING) && defined(CAN_CHROME)
	if (u_tex_chrome)
	{
		// attempts to mimic engine's R_StudioChrome
		vec3 dir = normalize(vec3(
			bone_normal[0][3] - u_chromeorg[0],
			bone_normal[1][3] - u_chromeorg[1],
			bone_normal[2][3] - u_chromeorg[2]));

		vec3 up = normalize(cross(dir, u_chromeright));
		vec3 side = normalize(cross(dir, up));

		vec3 up_anim = vec3(
			up[0] * bone_normal[0][0] + up[1] * bone_normal[1][0] + up[2] * bone_normal[2][0],
			up[0] * bone_normal[0][1] + up[1] * bone_normal[1][1] + up[2] * bone_normal[2][1],
			up[0] * bone_normal[0][2] + up[1] * bone_normal[1][2] + up[2] * bone_normal[2][2]);

		vec3 side_anim = vec3(
			side[0] * bone_normal[0][0] + side[1] * bone_normal[1][0] + side[2] * bone_normal[2][0],
			side[0] * bone_normal[0][1] + side[1] * bone_normal[1][1] + side[2] * bone_normal[2][1],
			side[0] * bone_normal[0][2] + side[1] * bone_normal[1][2] + side[2] * bone_normal[2][2]);

		// mikkotodo why the fuck this this needed???
		f_texcoord.x = 1.0 - (dot(a_normal, side_anim) + 1.0) * 0.5;
		f_texcoord.y = (dot(a_normal, up_anim) + 1.0) * 0.5;
	}
	else
#endif
	{
		f_texcoord = a_texcoord;
	}

#if defined(HAVE_GLOWSHELL)
	pos_anim += normal_anim * u_colormix.a;
	f_color = vec4(u_colormix.rgb, 1.0);

	// fudge the texcoords
	f_texcoord *= (1.0 / 8.0);
#elif defined(HAVE_ADDITIVE)
	f_color = vec4(vec3(u_colormix.a), 1.0);
#else
	
	#if defined(CAN_FULLBRIGHT)
	if (u_tex_fullbright)
	{
		f_color = vec4(vec3(1.0), u_colormix.a);
	}
	else
	#endif
	{
		// attempts to mimic engine's R_StudioLighting
		float result;

		float ambientlight = u_ambientlight;
		float shadelight = u_shadelight;

	#if defined(CAN_FLATSHADE)
		if (u_tex_flatshade)
		{
			result = ambientlight + (shadelight * 0.8);
		}
		else
	#endif
		{
			result = ambientlight + shadelight;

			float diffuse = dot(normal_anim, u_lightvec);

			// assumes that LAMBERT >= 1.0
			diffuse = (diffuse + (LAMBERT - 1.0)) * (1.0 / LAMBERT);
			result -= shadelight * max(0.0, diffuse);
		}

		result = clamp(result, 0.0, 1.0);
		result = gamma_correct(result);

		f_color = u_colormix;
		f_color.xyz *= result;

		// add elights, if any
	#if defined(HAVE_ELIGHTS)
		vec3 elights = vec3(0);
		
		for (int i = 0; i < MAX_ELIGHTS; i++)
		{
			vec3 dir = u_elight_pos[i].xyz - pos_anim;
			float NdotL = max(dot(normal_anim, dir), 0.0); // don't normalize!!!
		
			// wtf is this attenuation
			float mag_squared = dot(dir, dir);
			float rad_squared = u_elight_pos[i].w;
		
			float atten = rad_squared / (mag_squared * sqrt(mag_squared));
		
			elights += u_elight_color[i] * NdotL * atten;
		}
		
		f_color.rgb = elight_gamma(f_color.rgb, elights);
	#endif
	}
#endif

	vec4 result = gl_ModelViewProjectionMatrix * vec4(pos_anim, 1.0);

	// do fog in the vertex shader until someone complains
#ifdef HAVE_FOG
	// wtf is gl_FogCoord
	float fog_coord = result.w;
	
	#ifdef HAVE_FOG_LINEAR
		f_fog = (gl_Fog.end - fog_coord) * gl_Fog.scale;
	#else
		f_fog = exp(-gl_Fog.density * gl_Fog.density * fog_coord * fog_coord);
	#endif
	
	f_fog = clamp(f_fog, 0.0, 1.0);
#endif

	gl_Position = result;
}
