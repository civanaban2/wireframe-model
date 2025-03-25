/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:49:45 by cari              #+#    #+#             */
/*   Updated: 2025/03/25 05:49:50 by cari             ###   ########.fr       */
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
	void	*mlx;
	void	*win;
}	t_screen;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_camera
{
	int		isSphere;
	int		color_mode;
	float	x_trans;
	float	y_trans;
	float	zoom;
	float	z_scale;
	float	x_rotation;
	float	y_rotation;
	float	z_rotation;
}	t_camera;

typedef union u_color
{
	struct
	{
		__uint8_t	r;
		__uint8_t	g;
		__uint8_t	b;
	};
	__uint32_t	val;
}	t_color;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	t_color	color;
}	t_point;

typedef struct s_map
{
	t_point	**points;
	int		width;
	int		height;
	float	z_min;
	float	z_max;
}	t_map;

typedef struct s_core
{
	t_screen	screen;
	t_img		img;
	t_camera	camera;
	t_map		map;
}	t_core;

int		line_counter(char const *filename);
int		index_counter(char const *filename);
int		key_press(int keycode, t_core *core);
int 	close_window(t_core *core);
int		key_control(int keycode);
void 	zoom_hook(t_core *core, int keycode);
void	arg_check(int argc, char const *filename);
void	ft_error(char *message);
void	parse_map(char const *filename, t_map *map);
void	get_data(char const *filename, t_map *map);
void	init_core(t_core *core);
void	draw_map(t_core core);
void	reset_map(char *img_addr, int width, int height);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_lines(t_core core);
void	draw_line(t_core core, t_point point1, t_point point2);
void	close_hook(t_core *core, int keycode);
void	reset_hook(t_core *core, int keycode);
void 	rotation_hook(t_core *core, int keycode);
void 	translation_hook(t_core *core, int keycode);
void	free_split(char **split);
void	free_points (t_point **points, int height);
t_point **get_points(t_core core);
t_point	get_point(t_core core, int x, int y);
t_point	rotate(t_point point, t_camera camera);
t_point colorize(t_point point, int mode);
int	get_color(t_color color1, t_color color2, int i, int steps);
void color_hook(t_core *core, int keycode);
void	angle_hook(t_core *core, int keycode);
void	make_it_sphere(t_point *points, int width, int height);

#endif