/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:13:24 by cari              #+#    #+#             */
/*   Updated: 2025/03/25 01:00:17 by cari             ###   ########.fr       */
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
	double delta_x;
	double delta_y;
	double steps;
	double x_inc;
	double y_inc;
	double current_x;
	double current_y;
	int color;
	int i;

	delta_x = point2.x - point1.x;
	delta_y = point2.y - point1.y;

	steps = fabs(delta_x) > fabs(delta_y) ? fabs(delta_x) : fabs(delta_y);

	x_inc = delta_x / steps;
	y_inc = delta_y / steps;

	current_x = point1.x;
	current_y = point1.y;

	for (i = 0; i <= steps; i++)
	{
		color = get_color(point1.color, point2.color, i, steps);
		my_mlx_pixel_put(&core.img, (int)current_x, (int)current_y, color);
		current_x += x_inc;
		current_y += y_inc;
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
	if (core.camera.isSphere)
		make_it_sphere(&point, core.map.width * 50, core.map.height * 50, core.camera.zoom);
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

void	make_it_sphere(t_point *points, int width, int height, float zoom)
{
	float lng;
	float lat;

	lng = (points->x / (float)(width - 50.0 * zoom)) * 2 * M_PI - M_PI; 
	lat = (points->y / (float)(height - 50.0 * zoom)) * M_PI - (M_PI / 2);
	points->x = cos(lat) * cos(lng) * points->z;  // Yeni X
    points->y = cos(lat) * sin(lng) * points->z;  // Yeni Y
    points->z = sin(lat) * points->z;   
}