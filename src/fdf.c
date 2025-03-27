/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:49:59 by cari              #+#    #+#             */
/*   Updated: 2025/03/27 02:23:49 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char const *argv[])
{
	t_core	core;

	arg_check(argc, argv[1]);
	parse_map(argv[1], &core.map);
	init_core(&core);
	draw_map(core);
	mlx_hook(core.screen.win, 2, 1L << 0, key_press, &core);
	mlx_hook(core.screen.win, 17, 0, close_window, &core);
	mlx_loop(core.screen.mlx);
	return (0);
}

void	init_core(t_core *core)
{
	core->screen.mlx = mlx_init();
	core->screen.win = mlx_new_window(core->screen.mlx, WIDTH, HEIGHT, "FDF");
	core->img.img = mlx_new_image(core->screen.mlx, WIDTH, HEIGHT);
	core->img.addr = mlx_get_data_addr(core->img.img,
			&core->img.bits_per_pixel,
			&core->img.line_length, &core->img.endian);
	core->camera.zoom = 1;
	core->camera.x_trans = 0;
	core->camera.y_trans = 0;
	core->camera.z_scale = 10;
	core->camera.x_rotation = -M_PI / 180 * 35;
	core->camera.y_rotation = M_PI / 180 * 45;
	core->camera.z_rotation = 0;
	core->camera.color_mode = 1;
}
