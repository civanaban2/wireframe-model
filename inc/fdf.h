/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:49:45 by cari              #+#    #+#             */
/*   Updated: 2025/03/18 00:27:20 by cari             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <X11/keysym.h>

# define INVALID_ARGS "Invalid number of arguments.\n"
# define INVALID_FILE "Invalid file.\n"
# define INVALID_MAP "Invalid map.\n"

typedef struct s_core
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		**map;
	int		map_width;
	int		map_height;
	int		fd;
}	t_core;


#endif