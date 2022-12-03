## Main features

- Hor+ FOV scaling for widescreen
- Separately calculated viewmodel FOV
- Adjustable viewmodel origin
- Alternative viewmodel bob from CS:GO 1.0.0.40
- Viewmodel sway/lag
- Viewmodel shifting can be disabled
- Alternative crosshair
- Bodygroup-based arm changing depending on team
- Separate hand models for viewmodels (CS:GO/GMod style)
- Client-side weapon inspecting
- Bone controlled camera movement
- Mirrored shell ejects
- FOV lerp

## Notes

- Read the installation instructions. It's very easy to break your game if you don't.
- Play on VAC secured servers at your own risk.
- Some features will not work when running the game in D3D or software mode (viewmodel FOV, crosshair...).
- Some features will not work when cl_lw is set to 0 (inspecting, crosshair...).
- Other client-side mods like MetaHook might interfere with this.
- Some pirated clients (warzone) come with a program called gtlib which starts bitching when csldr is installed. To avoid this, csldr will remove GTLib.asi automatically when the game is launched. I'm not sure if this has any consequences but it seemed to work fine when I tested it.

## Installation

1. Download Windows binary from the [releases page](https://github.com/mikkokko/csldr/releases) or compile it from source
2. Navigate to "cstrike/cl_dlls" (or "czero/cl_dlls" if you're playing Condition Zero)
3. Rename the existing client.dll to client_orig.dll (client.so to client_orig.so on Linux)
4. Play

## Other stuff

- To get bone controlled camera movement working, make a bone called "camera" and make an attachment on it.
- You can make hand bodygroups change depending on what team you're in by naming the bodygroup so that is starts with "arms".
- Inspect sequence indices are hardcoded for compatibility, it's always the sequence after the last default sequence. Check inspectAnims array in inspect.c if in doubt.

## Cvars and commands
| Name | Description |
|-|-|
| camera_movement_interp | Smooths out camera movement. Recommended value is 30. Set to 0 to update camera movement every frame (no interpolation). |
| camera_movement_scale | Camera movement scale. |
| cl_bob_lower_amt | Specifies how much the viewmodel moves inwards for CS:GO style bob. |
| cl_bobamt_lat | Lateral scale for CS:GO style bob. |
| cl_bobamt_vert | Vertical scale for CS:GO style bob. |
| cl_bobstyle | 0 for default bob, 1 for old style bob and 2 for CS:GO style bob. |
| cl_mirror_knife | Mirrors the knife viewmodel. |
| cl_rollangle | Viewmodel roll angle. |
| cl_rollspeed | Viewmodel roll speed. |
| fov_horplus | Enables Hor+ scaling for FOV. Fixes the FOV when playing with aspect ratios besides 4:3. |
| fov_lerp | FOV interpolation time in seconds. |
| lookat | Inspects weapon if the animation is present. |
| mirror_shell | Switches the direction of shell ejects. |
| viewmodel_fov | Viewmodel FOV. |
| viewmodel_hands | Specifies an external hand model, for example "v_hands.mdl". Can be disabled with an empty string (""). |
| viewmodel_lag_scale | Scale of the viewmodel sway. |
| viewmodel_lag_speed | Speed of the viewmodel sway. |
| viewmodel_offset_x | Viewmodel's x offset. |
| viewmodel_offset_y | Viewmodel's y offset. |
| viewmodel_offset_z | Viewmodel's z offset. |
| viewmodel_shift | Fixes the viewmodel shift when looking up and down. 1 disables the shift without fixing the viewmodel position, 2 disables the shift and fixes the viewmodel position. |
| xhair_color_b | Crosshair color's blue value (0-1). |
| xhair_color_g | Crosshair color's green value (0-1). |
| xhair_color_r | Crosshair color's red value (0-1). |
| xhair_dot | Enables crosshair dot. |
| xhair_enable | Enables enhanced crosshair. |
| xhair_gap | Space between crosshair's lines. |
| xhair_pad | Border around crosshair. |
| xhair_size | Crosshair size. |
| xhair_t | Enables T-shaped crosshair. |
| xhair_thick | Crosshair thickness. |
