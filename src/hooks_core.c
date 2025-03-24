#include "fdf.h"

void reset_hook(t_core *core, int keycode)
{
	if (keycode == XK_r || keycode == XK_R)
	{
		core->camera.zoom = 1;
		core->camera.x_trans = 0;
		core->camera.y_trans = 0;
		core->camera.z_scale = 10;
		core->camera.x_rotation = -M_PI / 180 * 35;
		core->camera.y_rotation = M_PI / 180 * 45;
		core->camera.z_rotation = 0;
	}
}

void close_hook(t_core *core, int keycode)
{
	if (keycode == XK_Escape)
		close_window(core);
}

int close_window(t_core *core)
{
	free_points(core->map.points, core->map.height);
	mlx_destroy_image(core->screen.mlx, core->img.img);
	mlx_destroy_window(core->screen.mlx, core->screen.win);
	mlx_destroy_display(core->screen.mlx);
	free(core->screen.mlx);
	exit(0);
}

int key_control(int keycode)
{
	if (keycode == XK_A || keycode == XK_a || keycode == XK_D || keycode == XK_d)
		return (1);
	else if (keycode == XK_W || keycode == XK_w || keycode == XK_S || keycode == XK_s)
		return (1);
	else if (keycode == XK_Q || keycode == XK_q || keycode == XK_E || keycode == XK_e)
		return (1);
	else if (keycode == XK_R || keycode == XK_r || keycode == XK_Escape)
		return (1);
	else if (keycode == XK_U || keycode == XK_u || keycode == XK_J || keycode == XK_j)
		return (1);
	else if (keycode == XK_Y || keycode == XK_y || keycode == XK_H || keycode == XK_h)
		return (1);
	else if (keycode == XK_Up || keycode == XK_Down)
		return (1);
	else if (keycode == XK_Left || keycode == XK_Right)
		return (1);
	else if (keycode == XK_Z || keycode == XK_z || keycode == XK_X || keycode == XK_x)
		return (1);
	else if (keycode == XK_1 || keycode == XK_2 || keycode == XK_3 || keycode == XK_4)
		return (1);
	else if (keycode == XK_i || keycode == XK_I || keycode == XK_k || keycode == XK_K)
		return (1);
	else if (keycode == XK_g || keycode == XK_G)
		return (1);
	return (0);
}
