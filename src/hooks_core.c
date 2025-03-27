/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 06:53:58 by cari              #+#    #+#             */
/*   Updated: 2025/03/27 03:07:28 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int keycode, t_core *core)
{
	if (key_control(keycode))
	{
		close_hook(core, keycode);
		rotation_hook(core, keycode);
		translation_hook(core, keycode);
		zoom_hook(core, keycode);
		reset_hook(core, keycode);
		color_hook(core, keycode);
		angle_hook(core, keycode);
	}
	else
		return (0);
	draw_map(*core);
	return (0);
}

int	close_window(t_core *core)
{
	free_points(core->map.points, core->map.height);
	mlx_destroy_image(core->screen.mlx, core->img.img);
	mlx_destroy_window(core->screen.mlx, core->screen.win);
	mlx_destroy_display(core->screen.mlx);
	free(core->screen.mlx);
	exit(0);
}

void	reset_hook(t_core *core, int keycode)
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

void	close_hook(t_core *core, int keycode)
{
	if (keycode == XK_Escape)
		close_window(core);
}

int	key_control(int keycode)
{
	if (keycode == XK_A || keycode == XK_a
		|| keycode == XK_D || keycode == XK_d
		|| keycode == XK_W || keycode == XK_w
		|| keycode == XK_S || keycode == XK_s
		|| keycode == XK_Q || keycode == XK_q
		|| keycode == XK_E || keycode == XK_e
		|| keycode == XK_R || keycode == XK_r
		|| keycode == XK_U || keycode == XK_u
		|| keycode == XK_J || keycode == XK_j
		|| keycode == XK_Y || keycode == XK_y
		|| keycode == XK_H || keycode == XK_h
		|| keycode == XK_Up || keycode == XK_Down
		|| keycode == XK_Left || keycode == XK_Right
		|| keycode == XK_Z || keycode == XK_z
		|| keycode == XK_X || keycode == XK_x
		|| keycode == XK_1 || keycode == XK_2
		|| keycode == XK_3 || keycode == XK_4
		|| keycode == XK_5 || keycode == XK_6
		|| keycode == XK_Escape
		|| keycode == XK_i || keycode == XK_I
		|| keycode == XK_k || keycode == XK_K)
		return (1);
	return (0);
}
