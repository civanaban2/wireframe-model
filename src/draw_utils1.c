#include "fdf.h"

t_point get_point(t_core core, int x, int y)
{
	t_point point;

	double scale_X = (double) WIDTH / (core.map.width -1);
	double scale_Y = (double) HEIGHT / (core.map.height -1);

	if (scale_X > scale_Y)
		scale_X = scale_Y;
	else
		scale_Y = scale_X;
	point.x = core.map.points[y][x].x * scale_X * core.camera.zoom;
	point.y = core.map.points[y][x].y * scale_Y * core.camera.zoom;
	point.z = core.map.points[y][x].z * core.camera.z_scale;
	return (point);
}

void	draw_point(t_core core, int x, int y)
{
	t_point point;

	point = get_point(core, x, y);
	point = rotate(point, core.camera);
	point.x +=  (double) WIDTH / 2 + core.camera.x_trans;
	point.y +=  (double) HEIGHT / 2 + core.camera.y_trans;
	point.color = 0xFFFFFF;

	if (point_control(point.x, point.y, 1920, 1080))
		my_mlx_pixel_put(&core.img, point.x, point.y , point.color);
}

void	draw_points(t_core core)
{
	int x;
	int y;

	x = 0;
	while (x < core.map.width)
	{
		y = 0;
		while (y < core.map.height)
		{
			draw_point(core, x, y);
			y++;
		}
		x++;
	}
}

void	draw_line(t_core core, t_point point1, t_point point2)
{
	double delta_x;
	double delta_y;
	double step;
	double current_x;
	double current_y;

	point1 = rotate(point1, core.camera);
	point2 = rotate(point2, core.camera);
	delta_x = point2.x - point1.x;
	delta_y = point2.y - point1.y;
	point1.x += core.map.width / 2 - WIDTH / 2 + core.camera.x_trans;
	point1.y += core.map.height / 2 - HEIGHT / 2 + core.camera.y_trans;
	point2.x += core.map.width / 2 - WIDTH / 2 + core.camera.x_trans;
	point2.y += core.map.height / 2 - HEIGHT / 2 + core.camera.y_trans;

	step = delta_y / delta_x;
	int sign = delta_x > 0 ? 1 : -1;
	current_x = point1.x;
	current_y = point1.y;
	while (current_x < point2.x * sign)
	{
		if (point_control((int) current_x, (int) current_y, 1920, 1080))
			my_mlx_pixel_put(&core.img, (int) current_x, (int) current_y, 0x00FFFF);
		current_x += 1;
		current_y += step;
	}

}

void	draw_lines(t_core core)
{
	int x;
	int y;

	x = 0;
	while (x < core.map.width)
	{
		y = 0;
		while (y < core.map.height)
		{
			if (x < core.map.width - 1)
				draw_line(core, get_point(core, x, y), get_point(core, x + 1, y));
			if (y < core.map.height - 1)
				draw_line(core, get_point(core, x, y), get_point(core, x, y + 1));
			y++;
		}
		x++;
	}
}
