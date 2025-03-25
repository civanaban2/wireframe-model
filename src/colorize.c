#include "fdf.h"

t_point colorize(t_point point, int mode)
{
	if (mode == 1)
	{
		point.color.val = 0xFFFFFF;
	}
	else if (mode == 2)
	{
		if (point.z < 0)
			point.color.val = 0x0000FF;
		else if (point.z < 100)
			point.color.val = 0x00FF00;
		else if (point.z < 250)
			point.color.val = 0xADFF2F;
		else if (point.z < 500)
			point.color.val = 0xFFFF00;
		else if (point.z < 1000)
			point.color.val = 0xFFA500;
		else if (point.z < 1500)
			point.color.val = 0x8B4513;
		else if (point.z < 2500)
			point.color.val = 0x654321;
		else
			point.color.val = 0xFFFFFF;
	}
	else if (mode == 3)
	{
		if (point.z < 0)
			point.color.val = 0x654321;
		else if (point.z < 10)
			point.color.val = 0xEDC9AF;
		else if (point.z < 25)
			point.color.val = 0xD2691E;
		else if (point.z < 50)
			point.color.val = 0xA0522D;
		else if (point.z < 100)
			point.color.val = 0x8B4513;
		else if (point.z < 150)
			point.color.val = 0x704214;
		else if (point.z < 250)
			point.color.val = 0x696969;
		else
			point.color.val = 0xC0C0C0;
	}
	else if (mode == 4)
	{
		if (point.z < 0)
			point.color.val = 0x0000FF;
		else if (point.z < 10)
			point.color.val = 0x00FF00;
		else if (point.z < 25)
			point.color.val = 0xFF00;
		else
			point.color.val = 0xFFFFFF;		
	}
	return (point);
}

int	get_color(t_color color1, t_color color2, int i, int steps)
{
	t_color	color;

	if (steps == 0)
		return (color1.val);
	color.r = color1.r + (color2.r - color1.r) * i / steps;
	color.g = color1.g + (color2.g - color1.g) * i / steps;
	color.b = color1.b + (color2.b - color1.b) * i / steps;
	return (color.val);
}