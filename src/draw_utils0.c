#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	reset_map(char *img_addr, int width, int height)
{
	ft_memset(img_addr, 0, width * height * 4);
}

int	point_control(double x, double y, int x_offset, int y_offset)
{
	if (x < x_offset && x > 0 && y < y_offset && y > 0)
		return (1);
	return (0);
}

