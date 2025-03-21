/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cari <cari@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:49:45 by cari              #+#    #+#             */
/*   Updated: 2025/03/21 20:36:54 by cari             ###   ########.fr       */
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
	float	x_trans;
	float	y_trans;
	float	zoom;
	float	z_scale;
	float	x_rotation;
	float	y_rotation;
	float	z_rotation;
}	t_camera;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_map
{
	t_point	**points;
	int		width;
	int		height;	
}	t_map;

typedef struct s_core
{
	t_screen	screen;
	t_img		img;
	t_camera	camera;
	t_map		map;
}	t_core;

int		close_window(t_core *core);
int		key_press(int keycode, t_core *core);
void	parse_map(char const *filename, t_map *map);
void	arg_check(int argc, char const *filename);
void	draw_map(t_core core);
t_point	rotate(t_point point, t_camera camera);
t_point	rotate_x(t_point point, float angle);
t_point	rotate_y(t_point point, float angle);
t_point	rotate_z(t_point point, float angle);
void	parse_map(char const *filename, t_map *map);
int		line_counter(char const *filename);
int		index_counter(char const *filename);
void	get_data(char const *filename, t_map *map);
void	free_split(char **split);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	reset_map(char *img_addr, int width, int height);
int		point_control(float x, float y, int x_offset, int y_offset);
t_point	get_point(t_core core, int x, int y);
void	draw_point(t_core core, int x, int y);
void	draw_points(t_core core);
void	draw_line(t_core core, t_point point1, t_point point2);
void	draw_lines(t_core core);
int		close_window(t_core *core);
void	free_split(char **split);
void	init_core(t_core *core);
t_point	get_center(t_core core);
void	free_points (t_point **points, int height);
t_point	apply_transformations(t_point point, t_core core);
void	draw_line_recursive(t_img *img, float x, float y, float x_inc, float y_inc, float steps);
int	rotation_hooks(t_core *core, int keycode);
int	translation_hooks(t_core *core, int keycode);
int	zoom_hooks(t_core *core, int keycode);

#endif