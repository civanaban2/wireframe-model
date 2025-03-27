/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 06:52:25 by cari              #+#    #+#             */
/*   Updated: 2025/03/27 03:11:18 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	colorize(t_point point, int mode)
{
	if (mode == 1)
		point.color.val = 0xFFFFFF;
	else if (mode == 2)
		make_it_topographic(&point);
	else if (mode == 3)
		make_it_terrain(&point);
	else if (mode == 4)
		make_it_cartoon(&point);
	else if (mode == 5)
		make_it_realistic(&point);
	else if (mode == 6)
		free_palette(&point);
	return (point);
}

int	get_color(t_color color1, t_color color2, int i, int steps)
{
	t_color	color;

	if (steps == 0)
		return (color1.val);
	color.r = color1.r + (color2.r - color1.r) * i / steps;
	color.g = color1.g + (color2.g - color1.g) * i / steps;
	color.b = color1.b + (color2.b - color1.b) * i / steps;
	return (color.val);
}
