/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:38:45 by cari              #+#    #+#             */
/*   Updated: 2025/03/21 02:29:49 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int keycode, t_core *core)
{
	if (keycode == XK_Escape)
		close_window(core);
	if (keycode == XK_w || keycode == XK_W)
		core->camera.x_rotation += 0.1;
	else if (keycode == XK_s || keycode == XK_S)
		core->camera.x_rotation -= 0.1;
	else if (keycode == XK_a || keycode == XK_A)
		core->camera.y_rotation += 0.1;
	else if (keycode == XK_d || keycode == XK_D)
		core->camera.y_rotation -= 0.1;
	else if (keycode == XK_q || keycode == XK_Q)
		core->camera.z_rotation += 0.1;
	else if (keycode == XK_e || keycode == XK_E)
		core->camera.z_rotation -= 0.1;
	else if (keycode == XK_Up)
		core->camera.y_trans -= 100;
	else if (keycode == XK_Down)
		core->camera.y_trans += 100;
	else if (keycode == XK_Left)
		core->camera.x_trans -= 100;
	else if (keycode == XK_Right)
		core->camera.x_trans += 100;
	else if (keycode == XK_j || keycode == XK_J)
		core->camera.z_scale += 0.01;
	else if (keycode == XK_l || keycode == XK_L)
		core->camera.z_scale -= 0.01;
	else if (keycode == XK_z || keycode == XK_Z)
		core->camera.zoom += 0.5;
	else if (keycode == XK_x || keycode == XK_X)
		core->camera.zoom -= 0.5;
	else if (keycode == XK_r || keycode == XK_R)
	{
		core->camera.zoom = 1;
		core->camera.x_trans = 0;
		core->camera.y_trans = 0;
		core->camera.z_scale = 1;
		core->camera.x_rotation = 0;
		core->camera.y_rotation = 0;
		core->camera.z_rotation = 0;
	}
	else
		return (0);
	draw_map(*core);
	mlx_put_image_to_window(core->screen.mlx,
		core->screen.win, core->img.img, 0, 0);
	return (0);
}

int	close_window(t_core *core)
{
	mlx_destroy_window(core->screen.mlx, core->screen.win);
	exit(0);
}
