#include "fdf.h"

t_point get_point(t_core core, int x, int y)
{
	t_point point;

	double scale_X = (double) WIDTH / core.map.width;
	double scale_Y = (double) HEIGHT / core.map.height;

	if (scale_X > scale_Y)
		scale_X = scale_Y;
	else
		scale_Y = scale_X;
	point.x = core.map.points[y][x].x * scale_X * core.camera.zoom;
	point.y = core.map.points[y][x].y * scale_Y * core.camera.zoom;
	point.z = core.map.points[y][x].z * core.camera.z_scale / core.camera.z_divisor;
	return (point);
}

void	draw_point(t_core core, int x, int y)
{
	t_point point;

	point = get_point(core, x, y);
	point = rotate(point, core.camera);
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