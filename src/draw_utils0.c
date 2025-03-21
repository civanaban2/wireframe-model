/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:44:31 by cari              #+#    #+#             */
/*   Updated: 2025/03/21 20:18:48 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	reset_map(char *img_addr, int width, int height)
{
	ft_memset(img_addr, 0, width * height * 4);
}

int	point_control(float x, float y, int x_offset, int y_offset)
{
	if (x < x_offset && x > 0 && y < y_offset && y > 0)
		return (1);
	return (0);
}
