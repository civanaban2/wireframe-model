/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:38:11 by cari              #+#    #+#             */
/*   Updated: 2025/03/21 20:14:37 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	rotate(t_point point, t_camera camera)
{
	t_point	new_point;

	new_point.x = point.x * cos(camera.z_rotation) * cos(camera.x_rotation)
		+ point.y * (cos(camera.z_rotation)
			* sin(camera.x_rotation) * sin(camera.y_rotation)
			- sin(camera.z_rotation) * cos(camera.y_rotation))
		+ point.z * (cos(camera.z_rotation) * sin(camera.x_rotation)
			* cos(camera.y_rotation)
			+ sin(camera.z_rotation) * sin(camera.y_rotation));
	new_point.y = point.x * sin(camera.z_rotation) * cos(camera.x_rotation)
		+ point.y * (sin(camera.z_rotation) * sin(camera.x_rotation)
			* sin(camera.y_rotation) + cos(camera.z_rotation)
			* cos(camera.y_rotation))
		+ point.z * (sin(camera.z_rotation) * sin(camera.x_rotation)
			* cos(camera.y_rotation) - cos(camera.z_rotation)
			* sin(camera.y_rotation));
	new_point.z = point.x * sin(camera.x_rotation) * -1
		+ point.y * cos(camera.x_rotation) * sin(camera.y_rotation)
		+ point.z * cos(camera.x_rotation) * cos(camera.y_rotation);
	return (new_point);
}
