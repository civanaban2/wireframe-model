/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:38:45 by cari              #+#    #+#             */
/*   Updated: 2025/03/25 06:52:19 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int keycode, t_core *core)
{
	if (key_control(keycode))
	{
		close_hook(core, keycode);
		rotation_hook(core, keycode);
		translation_hook(core, keycode);
		zoom_hook(core, keycode);
		reset_hook(core, keycode);
		color_hook(core, keycode);
		angle_hook(core, keycode);
	}
	else
		return (0);
	draw_map(*core);
	return (0);
}
