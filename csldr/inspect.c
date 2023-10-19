#include "pch.h"

static float inspectEndTime;
static float oldViewAnimTime;
static int oldViewSequence;

static void SetInspectTime(studiohdr_t *hdr, int seq)
{
	float duration;
	mstudioseqdesc_t *desc;

	desc = (mstudioseqdesc_t *)((byte *)hdr + hdr->seqindex) + seq;

	duration = (float)desc->numframes / desc->fps;

	inspectEndTime = clientTime + duration;
}

static int inspectAnims[] =
{
	0, /* none */
	7, /* p228 */
	13, /* glock */
	5, /* scout */
	4, /* hegrenade */
	7, /* xm1014 */
	4, /* c4 */
	6, /* mac10 */
	6, /* aug */
	4, /* smokegrenade */
	16, /* elite */
	6, /* fiveseven */
	6, /* ump45 */
	5, /* sg550 */
	6, /* galil */
	6, /* famas */
	16, /* usp */
	13, /* glock18 */
	6, /* awp */
	6, /* mp5n */
	5, /* m249 */
	7, /* m3 */
	14, /* m4a1 */
	6, /* tmp */
	5, /* g3sg1 */
	4, /* flashbang */
	6, /* deagle */
	6, /* sg552 */
	6, /* ak47 */
	8, /* knife */
	6, /* p90 */
};

static int LookupInspect(int curSequence, int weaponID)
{
	if (weaponID <= WEAPON_NONE || weaponID >= (int)Q_ARRAYSIZE(inspectAnims))
		return -1;

	if (weaponID == WEAPON_USP)
	{
		if ((curSequence >= USP_UNSIL_IDLE) &&
			(curSequence != inspectAnims[weaponID]))
			return inspectAnims[weaponID] + 1;
	}
	else if (weaponID == WEAPON_M4A1)
		if ((curSequence >= M4A1_UNSIL_IDLE) &&
			(curSequence != inspectAnims[weaponID]))
			return inspectAnims[weaponID] + 1;

	return inspectAnims[weaponID];
}

static void Inspect_f(void)
{
	cl_entity_t *vm;
	studiohdr_t *studiohdr;
	int sequence;

	if (user1) /* spectating, don't inspect */
		return;

	/* currentWeapon can be used here because
	this code is never called when spectating */
	if (currentWeapon.m_fInReload || currentWeapon.m_fInSpecialReload)
		return;

	vm = gEngfuncs.GetViewModel();
	if (!vm)
		return;

	switch (currentWeaponId)
	{
		/* don't inspect if doing silencer stuff on usp/m4a1 */
		case WEAPON_USP:

			switch (vm->curstate.sequence)
			{
				case USP_ATTACH_SILENCER:
				case USP_DETACH_SILENCER:
					return;
			}

			break;

		case WEAPON_M4A1:

			switch (vm->curstate.sequence)
			{
				case M4A1_ATTACH_SILENCER:
				case M4A1_DETACH_SILENCER:
					return;
			}

			break;
	}

	studiohdr = (studiohdr_t *)vm->model->cache.data;
	if (!studiohdr)
		return;

	sequence = LookupInspect(vm->curstate.sequence, currentWeaponId);
	if (sequence < 0 || sequence >= studiohdr->numseq)
	{
		/* inspecting not supported or there's
		no inspect animation in this model */
		return;
	}

	SetInspectTime(studiohdr, sequence);

	gEngfuncs.pEventAPI->EV_WeaponAnimation(sequence, vm->curstate.body);
}

static bool IsIdleSequence(int seq)
{
	/* most idle animations have index of 0 */
	if (seq == 0)
		return true;

	/* handle idle animations that aren't 0 */
	switch (currentWeaponId)
	{
		case WEAPON_ELITE:
			return seq == ELITE_IDLE_LEFTEMPTY;
		case WEAPON_USP:
			return seq == USP_UNSIL_IDLE;
		case WEAPON_GLOCK18:
			return seq == GLOCK18_IDLE2 || seq == GLOCK18_IDLE3;
		case WEAPON_M4A1:
			return seq == M4A1_UNSIL_IDLE;
	}

	return false;
}

void InspectThink(void)
{
	if (inspectEndTime > clientTime)
	{
		cl_entity_t *vm = gEngfuncs.GetViewModel();

		if ((vm->curstate.animtime != oldViewAnimTime) &&
			IsIdleSequence(vm->curstate.sequence))
		{
			/* animation has changed and it's the idle animation, change back to inspect */
			vm->curstate.sequence = oldViewSequence;
			vm->curstate.animtime = oldViewAnimTime;
		}

		/* update vars */
		oldViewSequence = vm->curstate.sequence;
		oldViewAnimTime = vm->curstate.animtime;
	}
}

void InspectInit(void)
{
	gEngfuncs.pfnAddCommand("lookat", Inspect_f);
}
