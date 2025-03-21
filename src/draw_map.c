/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:44:10 by cari              #+#    #+#             */
/*   Updated: 2025/03/22 01:28:44 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_core core)
{
	reset_map(core.img.addr, 1920, 1080);
	draw_lines(core);
	mlx_put_image_to_window(core.screen.mlx,
		core.screen.win, core.img.img, 0, 0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	if (!point_control(x, y, WIDTH, HEIGHT))
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	reset_map(char *img_addr, int width, int height)
{
	ft_memset(img_addr, 0x0016161D, width * height * 4);
}

int	point_control(float x, float y, int x_offset, int y_offset)
{
	if (x < x_offset && x > 0 && y < y_offset && y > 0)
		return (1);
	return (0);
}
