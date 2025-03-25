/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 06:54:29 by cari              #+#    #+#             */
/*   Updated: 2025/03/25 06:56:21 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_hook(t_core *core, int keycode)
{
	if (keycode == XK_u || keycode == XK_U)
		core->camera.z_scale += 0.05;
	else if (keycode == XK_j || keycode == XK_J)
		core->camera.z_scale -= 0.05;
	else if (keycode == XK_y || keycode == XK_Y)
		core->camera.z_scale += 0.5;
	else if (keycode == XK_h || keycode == XK_H)
		core->camera.z_scale -= 0.5;
	else if (keycode == XK_z || keycode == XK_Z)
		core->camera.zoom += 0.05;
	else if (keycode == XK_x || keycode == XK_X)
		core->camera.zoom -= 0.05;
	if (core->camera.z_scale < 0.0)
		core->camera.z_scale = 0.0;
	if (core->camera.zoom < 0.0)
		core->camera.zoom = 0.0;
}

void	rotation_hook(t_core *core, int keycode)
{
	if (keycode == XK_w || keycode == XK_W)
		core->camera.y_rotation += M_PI / 180 * 10;
	else if (keycode == XK_s || keycode == XK_S)
		core->camera.y_rotation -= M_PI / 180 * 10;
	else if (keycode == XK_a || keycode == XK_A)
		core->camera.x_rotation -= M_PI / 180 * 10;
	else if (keycode == XK_d || keycode == XK_D)
		core->camera.x_rotation += M_PI / 180 * 10;
	else if (keycode == XK_q || keycode == XK_Q)
		core->camera.z_rotation -= M_PI / 180 * 10;
	else if (keycode == XK_e || keycode == XK_E)
		core->camera.z_rotation += M_PI / 180 * 10;
	if (core->camera.x_rotation > 2 * M_PI - 0.1)
		core->camera.x_rotation = 0;
	if (core->camera.x_rotation < -2 * M_PI + 0.1)
		core->camera.x_rotation = 0;
	if (core->camera.y_rotation > 2 * M_PI - 0.1)
		core->camera.y_rotation = 0;
	if (core->camera.y_rotation < -2 * M_PI + 0.1)
		core->camera.y_rotation = 0;
	if (core->camera.z_rotation > 2 * M_PI - 0.1)
		core->camera.z_rotation = 0;
	if (core->camera.z_rotation < -2 * M_PI + 0.1)
		core->camera.z_rotation = 0;
}

void	translation_hook(t_core *core, int keycode)
{
	if (keycode == XK_Up)
		core->camera.y_trans -= 10;
	else if (keycode == XK_Down)
		core->camera.y_trans += 10;
	else if (keycode == XK_Left)
		core->camera.x_trans -= 10;
	else if (keycode == XK_Right)
		core->camera.x_trans += 10;
}

void	color_hook(t_core *core, int keycode)
{
	if (keycode == XK_1)
		core->camera.color_mode = 1;
	else if (keycode == XK_2)
		core->camera.color_mode = 2;
	else if (keycode == XK_3)
		core->camera.color_mode = 3;
	else if (keycode == XK_4)
		core->camera.color_mode = 4;
}

void	angle_hook(t_core *core, int keycode)
{
	if (keycode == XK_i || keycode == XK_I)
	{
		core->camera.x_rotation = -M_PI / 180 * 35;
		core->camera.y_rotation = M_PI / 180 * 45;
		core->camera.z_rotation = 0;
	}
	else if (keycode == XK_k || keycode == XK_K)
	{
		core->camera.x_rotation = 0;
		core->camera.y_rotation = 0;
		core->camera.z_rotation = 0;
	}
	else if (keycode == XK_g || keycode == XK_G)
	{
		core->camera.isSphere = !core->camera.isSphere;
	}	
}
