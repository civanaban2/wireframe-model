/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:13:24 by cari              #+#    #+#             */
/*   Updated: 2025/03/25 04:41:27 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_lines(t_core core)
{
	int x;
	int y;
	t_point **points;

	points = get_points(core);
	x = 0;
	while (x < core.map.width)
	{
		y = 0;
		while (y < core.map.height)
		{
			if (x < core.map.width - 1)
				draw_line(core, points[y][x], points[y][x + 1]);
			if (y < core.map.height - 1)
				draw_line(core, points[y][x], points[y + 1][x]);
			y++;
		}
		x++;
	}
	free_points(points, core.map.height);
}

void draw_line(t_core core, t_point point1, t_point point2)
{
	float delta_x;
	float delta_y;
	float hippo;
	float step;
	float r_step;
	float g_step;
	float b_step;
	int color;
	int i;

	i = 0;
	delta_x = point2.x - point1.x;
	delta_y = point2.y - point1.y;

	hippo = sqrtf(delta_x * delta_x + delta_y * delta_y);
	step = fmax(fabs(delta_x), fabs(delta_y));	
	r_step = (float) (point2.color.r - point1.color.r) / hippo;
	g_step = (float) (point2.color.g - point1.color.g) / hippo;
	b_step = (float) (point2.color.b - point1.color.b) / hippo;
	color = point1.color.val;
	while (hippo-- > 0)
	{
		my_mlx_pixel_put(&core.img, (int)point1.x, (int)point1.y, point1.color.val);
		if (point1.x != point2.x)
			point1.x += delta_x / step;
		if (point1.y != point2.y)
			point1.y += delta_y / step;
		point1.color.r += r_step;
		point1.color.g += g_step;
		point1.color.b += b_step;
		i++;
	}	
}

t_point get_point(t_core core, int x, int y)
{
	t_point point;

	point.x = core.map.points[y][x].x * core.camera.zoom;
	point.y = core.map.points[y][x].y * core.camera.zoom;
	point.z = core.map.points[y][x].z * core.camera.z_scale;
	point = colorize(point, core.camera.color_mode);
	point.z *= core.camera.zoom;
	point = rotate(point, core.camera);
	point.x += core.camera.x_trans + WIDTH / 2;
	point.y += core.camera.y_trans + HEIGHT / 2;
	return (point);
}

t_point **get_points(t_core core)
{
	t_point **points;
	int x;
	int y;

	points = (t_point **)malloc(sizeof(t_point *) * core.map.height);
	y = 0;
	while (y < core.map.height)
	{
		points[y] = (t_point *)malloc(sizeof(t_point) * core.map.width);
		x = 0;
		while (x < core.map.width)
		{
			points[y][x] = get_point(core, x, y);
			x++;
		}
		y++;
	}
	return (points);
}
