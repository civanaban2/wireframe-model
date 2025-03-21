/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:13:24 by cari              #+#    #+#             */
/*   Updated: 2025/03/22 02:10:31 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_lines(t_core core)
{
	int x;
	int y;

	x = 0;
	while (x < core.map.width)
	{
		y = 0;
		while (y < core.map.height)
		{
			if (x < core.map.width - 1)
				draw_line(core, get_point(core, x, y), get_point(core, x + 1, y));
			if (y < core.map.height - 1)
				draw_line(core, get_point(core, x, y), get_point(core, x, y + 1));
			y++;
		}
		x++;
	}
}

void	draw_line(t_core core, t_point point1, t_point point2)
{
	double delta_x;
	double delta_y;
	double steps;
	double x_inc;
	double y_inc;
	double current_x;
	double current_y;
	int i;

	point1 = rotate(point1, core.camera);
	point2 = rotate(point2, core.camera);

	delta_x = point2.x - point1.x;
	delta_y = point2.y - point1.y;

	steps = fabs(delta_x) > fabs(delta_y) ? fabs(delta_x) : fabs(delta_y);

	x_inc = delta_x / steps;
	y_inc = delta_y / steps;

	point1.x += core.camera.x_trans + WIDTH / 2;
	point1.y += core.camera.y_trans + HEIGHT / 2;
	point2.x += core.camera.x_trans + WIDTH / 2;
	point2.y += core.camera.y_trans + HEIGHT / 2;

	current_x = point1.x;
	current_y = point1.y;

	for (i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(&core.img, (int)current_x, (int)current_y, 0xFFFFFF);
		current_x += x_inc;
		current_y += y_inc;
	}
}

t_point get_point(t_core core, int x, int y)
{
	t_point point;

	
	point.x = core.map.points[y][x].x * core.camera.zoom ;
	point.y = core.map.points[y][x].y * core.camera.zoom ;
	point.z = core.map.points[y][x].z * core.camera.z_scale * core.camera.zoom;
	return (point);
}

