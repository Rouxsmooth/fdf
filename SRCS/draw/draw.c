/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:49:03 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/26 19:28:46 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

void	put_pixel(t_vals *vals)
{
	int	*pixel;
	int	temp;
	int	size_line;

	pixel = (int *) mlx_get_data_addr(vals->img, &temp, &size_line, &temp);
	pixel[vals->point.y * vals->width + vals->point.x] = vals->point.color;
}

unsigned int	getcolor(char *hexinstr)
{
	int				i;
	char			*base;
	unsigned int	nbr;
	int				start;

	nbr = 0;
	start = ft_strstrindex(hexinstr, "0x") + 2;
	if (start == 1)
		return (0xFFFFFF);
	if (ft_strchr(&hexinstr[start], 'a') || ft_strchr(&hexinstr[start], 'b')
		|| ft_strchr(&hexinstr[start], 'c') || ft_strchr(&hexinstr[start], 'd')
		|| ft_strchr(&hexinstr[start], 'e') || ft_strchr(&hexinstr[start], 'f'))
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	while (hexinstr[start])
	{
		nbr *= 16;
		i = 0;
		while (hexinstr[start] != base[i])
			i++;
		nbr += i;
		start++;
	}
	return (nbr);
}

t_point	get_iso(t_point point, t_vals *vals)
{
	int prev_x;
	int prev_y;

	prev_x = point.x * vals->map_ratio;
	prev_y = point.y * vals->map_ratio;
	point.x = (prev_x - prev_y) * cos(30 * M_PI / 180);
	point.y = (prev_x + prev_y) * sin(30 * M_PI / 180) - (point.z * vals->map_ratio);
	return (point);
}

void	drawlow(t_vals *vals, t_point p1, t_point p2)
{
	int	dx;
	int	dy;
	int	err;
	int	inc;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	inc = 1;
	if (dy < 0)
		inc = -1;
	dy *= inc;
	err = 2 * dy - dx;
	while (p1.x != p2.x)
	{
		vals->point = p1;
		put_pixel(vals);
		if (err > 0)
		{
			p1.y += inc;
			err += 2 * (dy - dx);
		}
		else
			err += 2 * dy;
		p1.x += inc;
	}
	return ;
}

void	drawhigh(t_vals *vals, t_point p1, t_point p2)
{
	int	dx;
	int	dy;
	int	err;
	int	inc;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	inc = 1;
	if (dx < 0)
		inc = -1;
	dx *= inc;
	err = 2 * dx - dy;
	while (p1.y != p2.y)
	{
		vals->point = p1;
		put_pixel(vals);
		if (err > 0)
		{
			p1.x += inc;
			err += 2 * (dx - dy);
		}
		else
			err += 2 * dx;
		p1.y += inc;
	}
	return ;
}

void create_line(t_vals *vals, t_point p1, t_point p2)
{
	ft_printf("\t\t%d %d | %d %d\n", p1.x, p2.x, p1.y, p2.x);
	if (ft_abs(p2.y - p1.y) < ft_abs(p2.x - p1.x))
	{
		if (p1.x > p2.x)
			return (drawlow(vals, p2, p1));
		return (drawlow(vals, p1, p2));
	}
	if (p1.y > p2.y)
		return (drawhigh(vals, p2, p1));
	return (drawhigh(vals, p1, p2));
}

t_point	setpoint(int x, int y, char *z, char *color)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = ft_atoi(z);
	point.color = getcolor(color);
	return (point);
}

void	draw_map(t_vals *vals)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	y = 0;
	while (y < vals->array_height - 1)
	{
		// ft_printf("y : %d\n", y);
		x = 0;
		while (x < vals->array_width)
		{
			// ft_printf("\tx : %d\n", x);
			p1 = setpoint(x, y, vals->array[y][x], vals->array[y][x]);
			if (x < vals->array_width - 1)
			{
				p2 = setpoint(x + 1, y, vals->array[y][x + 1], vals->array[y + 1][x]);
				create_line(vals, p1, p2);
			}
			if (y < vals->array_height - 1)
			{
				p2 = setpoint(x, y + 1, vals->array[y + 1][x], vals->array[y + 1][x]);
				create_line(vals, p1, p2);
			}
			x++;
		}
		y++;
	}
}

// void	draw_map(t_vals *vals)
// {
// 	int		x;
// 	int		y;
// 	t_point	p1;
// 	t_point	p2_h;
// 	t_point	p2_v;

// 	y = 0;
// 	while (y < vals->array_height)
// 	{
// 		x = 0;
// 		while (x < vals->array_width)
// 		{
// 			p1 = setpoint(x, y, vals->array[y][x], vals->array[y][x]);

// 			if (x < vals->array_width - 1)
// 			{
// 				p2_h = setpoint(x + 1, y, vals->array[y][x + 1], vals->array[y][x + 1]);
// 				create_line(vals, p1, p2_h);
// 			}
// 			if (y < vals->array_height - 1)
// 			{
// 				p2_v = setpoint(x, y + 1, vals->array[y + 1][x], vals->array[y + 1][x]);
// 				create_line(vals, p1, p2_v);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }
