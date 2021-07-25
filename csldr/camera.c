#include "pch.h"

/* animate camera using a viewmodel attachment */

cvar_t *camera_movement_scale;

void CameraInit(void)
{
	camera_movement_scale = gEngfuncs.pfnRegisterVariable("camera_movement_scale", "1", FCVAR_ARCHIVE);
}

float EstimateFrame(cl_entity_t *entity, mstudioseqdesc_t *seqdesc)
{
	float time;
	float dfdt, f;

	time = clientTime;

	if (time < entity->curstate.animtime)
		dfdt = 0.0f;
	else
		dfdt = (time - entity->curstate.animtime) * entity->curstate.framerate * seqdesc->fps;

	if (seqdesc->numframes <= 1)
		f = 0.0f;
	else
		f = (entity->curstate.frame * (seqdesc->numframes - 1)) / 256.0f;

	f += dfdt;

	if (seqdesc->flags & STUDIO_LOOPING)
	{
		if (seqdesc->numframes > 1)
			f -= (int)(f / (seqdesc->numframes - 1)) * (seqdesc->numframes - 1);

		if (f < 0)
			f += (seqdesc->numframes - 1);
	}
	else
	{
		if (f >= seqdesc->numframes - 1.001f)
			f = seqdesc->numframes - 1.001f;

		if (f < 0.0f)
			f = 0.0f;
	}

	return f;
}

mstudioanim_t *GetAnim(studiohdr_t *hdr, model_t *model, mstudioseqdesc_t *seqdesc)
{
	cache_user_t *sequences;

	if (seqdesc->seqgroup == 0)
		return (mstudioanim_t *)((byte *)hdr + seqdesc->animindex);

	sequences = (cache_user_t *)model->submodels;

	return (mstudioanim_t *)((byte *)sequences[seqdesc->seqgroup].data + seqdesc->animindex);
}

void CalcBoneAngles(int frame, float s, mstudiobone_t *bone, mstudioanim_t *anim, vec3_t angles)
{
	int j, k;
	vec3_t angle1, angle2;
	mstudioanimvalue_t *animvalue;

	for (j = 0; j < 3; j++)
	{
		if (anim->offset[j + 3] == 0)
			angle2[j] = angle1[j] = bone->value[j + 3];
		else
		{
			animvalue = (mstudioanimvalue_t *)((byte *)anim + anim->offset[j + 3]);
			k = frame;

			if (animvalue->num.total < animvalue->num.valid)
				k = 0;

			while (animvalue->num.total <= k)
			{
				k -= animvalue->num.total;
				animvalue += animvalue->num.valid + 1;

				if (animvalue->num.total < animvalue->num.valid)
					k = 0;
			}

			if (animvalue->num.valid > k)
			{
				angle1[j] = animvalue[k + 1].value;

				if (animvalue->num.valid > k + 1)
					angle2[j] = animvalue[k + 2].value;
				else
				{
					if (animvalue->num.total > k + 1)
						angle2[j] = angle1[j];
					else
						angle2[j] = animvalue[animvalue->num.valid + 2].value;
				}
			}
			else
			{
				angle1[j] = animvalue[animvalue->num.valid].value;

				if (animvalue->num.total > k + 1)
					angle2[j] = angle1[j];
				else
					angle2[j] = animvalue[animvalue->num.valid + 2].value;
			}

			angle1[j] = bone->value[j + 3] + angle1[j] * bone->scale[j + 3];
			angle2[j] = bone->value[j + 3] + angle2[j] * bone->scale[j + 3];
		}
	}

	angle1[0] *= 180.0f / FL_PI;
	angle1[1] *= 180.0f / FL_PI;
	angle1[2] *= 180.0f / FL_PI;
	angle2[0] *= 180.0f / FL_PI;
	angle2[1] *= 180.0f / FL_PI;
	angle2[2] *= 180.0f / FL_PI;

	VectorLerp(angle1, angle2, s, angles);
}

int GetCameraBone(studiohdr_t *hdr)
{
	int i;
	mstudioattachment_t *a;
	mstudiobone_t *b;

	a = (mstudioattachment_t *)((byte *)hdr + hdr->attachmentindex);

	for (i = 0; i < hdr->numattachments; i++, a++)
	{
		b = (mstudiobone_t *)((byte *)hdr + hdr->boneindex) + a->bone;
		if (!strcmp(b->name, "camera"))
			return a->bone;
	}

	return -1;
}

/* stupid shit im sick of shit */
vec3_t cameraAngles;
bool cameraMovement;

void CameraCalcMovement(cl_entity_t *vm)
{
	model_t *model;
	studiohdr_t *hdr;
	int bone_index;
	int sequence;
	mstudioseqdesc_t *seqdesc;
	mstudioanim_t *anim;
	int frame;
	mstudiobone_t *bone;
	float f, s;

	model = vm->model;
	hdr = (studiohdr_t *)model->cache.data;

	bone_index = GetCameraBone(hdr);

	if (bone_index == -1)
	{
		cameraMovement = false;
		return;
	}

	sequence = vm->curstate.sequence;

	if (sequence >= hdr->numseq)
		sequence = 0;

	seqdesc = (mstudioseqdesc_t *)((byte *)hdr + hdr->seqindex) + sequence;

	f = EstimateFrame(vm, seqdesc);

	if (f > seqdesc->numframes - 1)
		f = 0.0f;
	else if (f < -0.01f)
		f = -0.01f;

	anim = GetAnim(hdr, model, seqdesc) + bone_index;
	bone = (mstudiobone_t *)((byte *)hdr + hdr->boneindex) + bone_index;

	frame = (int)f;
	s = (f - frame);

	CalcBoneAngles(frame, s, bone, anim, cameraAngles);
	cameraMovement = true;
}

void CameraApplyMovement(ref_params_t *pparams)
{
	float scale;

	if (!cameraMovement)
		return;

	scale = camera_movement_scale->value;

	/* fuck this
	LerpCameraAngles(cameraAngles); */

	pparams->viewangles[0] += cameraAngles[0] * scale;
	pparams->viewangles[1] += cameraAngles[1] * scale;
	pparams->viewangles[2] += cameraAngles[2] * scale;
}