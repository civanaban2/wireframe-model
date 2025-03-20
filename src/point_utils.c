/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:13:24 by cari              #+#    #+#             */
/*   Updated: 2025/03/21 01:13:28 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point get_point(t_core core, int x, int y)
{
	t_point point;

	double scale_X = (double) WIDTH / (core.map.width -1);
	double scale_Y = (double) HEIGHT / (core.map.height -1);

	if (scale_X > scale_Y)
		scale_X = scale_Y;
	else
		scale_Y = scale_X;
	point.x = core.map.points[y][x].x * scale_X * core.camera.zoom;
	point.y = core.map.points[y][x].y * scale_Y * core.camera.zoom;
	point.z = core.map.points[y][x].z * core.camera.z_scale;
	return (point);
}