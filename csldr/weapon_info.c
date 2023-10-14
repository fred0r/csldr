#include "pch.h"

weapon_data_t currentWeapon;

void Hk_PostRunCmd(local_state_t *from,
		local_state_t *to,
		usercmd_t *cmd,
		int runfuncs,
		double time,
		unsigned int random_seed)
{
	currentWeapon = from->weapondata[from->client.m_iId];

	// crosshair stuff
	xhairPlayerFlags = from->client.flags;
	xhairPlayerSpeed = VectorLength(from->client.velocity);
	xhairWeaponFlags = currentWeapon.m_iWeaponState;

	cl_funcs.pPostRunCmd(from, to, cmd, runfuncs, time, random_seed);
}
