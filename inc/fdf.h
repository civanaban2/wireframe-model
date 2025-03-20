/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:49:45 by cari              #+#    #+#             */
/*   Updated: 2025/03/20 20:25:54 by cari             ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_screen
{
	void *mlx;
	void *win;
}	t_screen;

typedef struct s_img
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}	t_img;

typedef struct s_camera
{
	int x_offset;
	int y_offset;
	float zoom;
	float z_divisor;
	float z_scale;
	float x_rotation;
	float y_rotation;
	float z_rotation;
}	t_camera;

typedef struct s_point
{
	double x;
	double y;
	double z;
	int color;
}	t_point;

typedef struct s_map
{
	t_point **points;
	int width;
	int height;	
}	t_map;

typedef struct s_core
{
	t_screen screen;
	t_img img;
	t_camera camera;
	t_map map;
}	t_core;

int 	close_window(t_core *core);
int 	key_press(int keycode, t_core *core);
void	parse_map(char const *filename, t_map *map);
void	arg_check(int argc, char const *filename);
void	draw_map(t_core core);
t_point	rotate(t_point point, t_camera camera);
t_point	rotate_x(t_point point, double angle);
t_point	rotate_y(t_point point, double angle);
t_point	rotate_z(t_point point, double angle);
void	parse_map(char const *filename, t_map *map);
int	line_counter(char const *filename);
int	index_counter(char const *filename);
void	get_data(char const *filename, t_map *map);
void	free_split(char **split);

#endif