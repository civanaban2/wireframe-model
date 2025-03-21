/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:38:45 by cari              #+#    #+#             */
/*   Updated: 2025/03/22 02:11:33 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int keycode, t_core *core)
{
	if (keycode == XK_Escape)
		close_window(core);
	if (rotation_hooks(core, keycode))
		;
	else if (translation_hooks(core, keycode))
		;
	else if (zoom_hooks(core, keycode))
		;
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
	return (0);
}

int	close_window(t_core *core)
{
	free_points(core->map.points, core->map.height);
	mlx_destroy_image(core->screen.mlx, core->img.img);
	mlx_destroy_window(core->screen.mlx, core->screen.win);
	mlx_destroy_display(core->screen.mlx);
	exit(0);
}

int	rotation_hooks(t_core *core, int keycode)
{
	if (keycode == XK_w || keycode == XK_W)
	{
		core->camera.y_rotation += 0.5;
		return (1);
	}
	else if (keycode == XK_s || keycode == XK_S)
	{
		core->camera.y_rotation -= 0.5;
		return (1);
	}
	else if (keycode == XK_a || keycode == XK_A)
	{
		core->camera.x_rotation -= 0.5;
		return (1);
	}
	else if (keycode == XK_d || keycode == XK_D)
	{
		core->camera.x_rotation += 0.5;
		return (1);
	}
	else if (keycode == XK_q || keycode == XK_Q)
	{
		core->camera.z_rotation -= 0.5;
		return (1);
	}
	else if (keycode == XK_e || keycode == XK_E)
	{
		core->camera.z_rotation += 0.5;
		return (1);
	}
	return (0);
}

int	translation_hooks(t_core *core, int keycode)
{
	if (keycode == XK_Up)
	{
		core->camera.y_trans -= 100;
		return (1);
	}
	else if (keycode == XK_Down)
	{
		core->camera.y_trans += 100;
		return (1);
	}
	else if (keycode == XK_Left)
	{
		core->camera.x_trans -= 100;
		return (1);
	}
	else if (keycode == XK_Right)
	{
		core->camera.x_trans += 100;
		return (1);
	}
	return (0);
}

int	zoom_hooks(t_core *core, int keycode)
{
	if (keycode == XK_j || keycode == XK_J)
	{
		core->camera.z_scale += 0.05;
		return (1);
	}
	else if (keycode == XK_l || keycode == XK_L)
	{
		core->camera.z_scale -= 0.05;
		return (1);
	}
	else if (keycode == XK_z || keycode == XK_Z)
	{
		core->camera.zoom += 0.1;
		return (1);
	}
	else if (keycode == XK_x || keycode == XK_X)
	{
		core->camera.zoom -= 0.1;
		return (1);
	}
	return (0);
}
