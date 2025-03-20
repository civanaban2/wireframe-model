/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:38:11 by cari              #+#    #+#             */
/*   Updated: 2025/03/20 23:38:32 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	rotate_x(t_point point, double angle)
{
	t_point	new_point;

	new_point.x = point.x;
	new_point.y = point.y * cos(angle) - point.z * sin(angle);
	new_point.z = point.z * cos(angle) - point.y * sin(angle);
	new_point.color = point.color;
	return (new_point);
}

t_point	rotate_y(t_point point, double angle)
{
	t_point	new_point;

	new_point.x = point.x * cos(angle) - point.z * sin(angle);
	new_point.y = point.y;
	new_point.z = point.x * sin(angle) + point.z * cos(angle);
	new_point.color = point.color;
	return (new_point);
}

t_point	rotate_z(t_point point, double angle)
{
	t_point	new_point;

	new_point.x = point.x * cos(angle) + point.y * sin(angle);
	new_point.y = point.y * cos(angle) - point.x * sin(angle);
	new_point.z = point.z;
	new_point.color = point.color;
	return (new_point);
}

t_point	rotate(t_point point, t_camera camera)
{
	point = rotate_x(point, camera.x_rotation);
	point = rotate_y(point, camera.y_rotation);
	point = rotate_z(point, camera.z_rotation);
	return (point);
}
