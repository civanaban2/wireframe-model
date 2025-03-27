/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 03:10:40 by cari              #+#    #+#             */
/*   Updated: 2025/03/27 03:49:52 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_it_topographic(t_point *point)
{
	if (point->z < -400)
		point->color.val = 0x0000FF;
	else if (point->z < -200)
		point->color.val = 0x0099FF;
	else if (point->z < 0)
		point->color.val = 0x00FF66;
	else if (point->z < 10)
		point->color.val = 0x66FF33;
	else if (point->z < 20)
		point->color.val = 0xCCFF33;
	else if (point->z < 40)
		point->color.val = 0xFFFF00;
	else if (point->z < 100)
		point->color.val = 0xFF9900;
	else if (point->z < 200)
		point->color.val = 0xFF6600;
	else if (point->z < 300)
		point->color.val = 0xCC3300;
	else if (point->z < 400)
		point->color.val = 0x990000;
	else if (point->z < 600)
		point->color.val = 0x666666;
	else
		point->color.val = 0xFFFFFF;
}

void	make_it_terrain(t_point *point)
{
	if (point->z < -400)
		point->color.val = 0x0044CC;
	else if (point->z < -200)
		point->color.val = 0x0088CC;
	else if (point->z < 0)
		point->color.val = 0x55AA55;
	else if (point->z < 10)
		point->color.val = 0x88BB66;
	else if (point->z < 20)
		point->color.val = 0xDDCC77;
	else if (point->z < 40)
		point->color.val = 0xAA8844;
	else if (point->z < 100)
		point->color.val = 0x996633;
	else if (point->z < 200)
		point->color.val = 0x775522;
	else if (point->z < 300)
		point->color.val = 0x554433;
	else if (point->z < 400)
		point->color.val = 0x333333;
	else if (point->z < 600)
		point->color.val = 0x999999;
	else
		point->color.val = 0xFFFFFF;
}

void	make_it_cartoon(t_point *point)
{
	if (point->z < -400)
		point->color.val = 0x2C3E50;
	else if (point->z < -200)
		point->color.val = 0x34495E;
	else if (point->z < 0)
		point->color.val = 0x27AE60;
	else if (point->z < 10)
		point->color.val = 0x1ABC9C;
	else if (point->z < 20)
		point->color.val = 0x16A085;
	else if (point->z < 40)
		point->color.val = 0xF39C12;
	else if (point->z < 100)
		point->color.val = 0xE67E22;
	else if (point->z < 200)
		point->color.val = 0xD35400;
	else if (point->z < 300)
		point->color.val = 0xC0392B;
	else if (point->z < 400)
		point->color.val = 0x8E44AD;
	else if (point->z < 600)
		point->color.val = 0x2980B9;
	else
		point->color.val = 0x95A5A6;
}

void	make_it_realistic(t_point *point)
{
	if (point->z < -400)
		point->color.val = 0x004080;
	else if (point->z < -200)
		point->color.val = 0x0066CC;
	else if (point->z < 0)
		point->color.val = 0x66B3FF;
	else if (point->z < 10)
		point->color.val = 0xA1D490;
	else if (point->z < 20)
		point->color.val = 0x8FBF8F;
	else if (point->z < 40)
		point->color.val = 0xA1C8A0;
	else if (point->z < 100)
		point->color.val = 0x6B8E23;
	else if (point->z < 200)
		point->color.val = 0x8B7D4E;
	else if (point->z < 300)
		point->color.val = 0xA0522D;
	else if (point->z < 400)
		point->color.val = 0x8B4513;
	else if (point->z < 600)
		point->color.val = 0xD2691E;
	else
		point->color.val = 0xFFFFFF;
}

void	free_palette(t_point *point)
{
	if (point->z < -400)
		point->color.val = 0x1C1C1C;
	else if (point->z < -200)
		point->color.val = 0x800000;
	else if (point->z < 0)
		point->color.val = 0x9B111E;
	else if (point->z < 10)
		point->color.val = 0xC0392B;
	else if (point->z < 20)
		point->color.val = 0x7F1F00;
	else if (point->z < 40)
		point->color.val = 0xF39C12;
	else if (point->z < 100)
		point->color.val = 0xD35400;
	else if (point->z < 200)
		point->color.val = 0x8B0000;
	else if (point->z < 300)
		point->color.val = 0xFF6347;
	else if (point->z < 400)
		point->color.val = 0x4B0082;
	else if (point->z < 600)
		point->color.val = 0xFFD700;
	else
		point->color.val = 0x2E2E2E;
}
