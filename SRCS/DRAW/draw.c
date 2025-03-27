/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:49:03 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/27 18:54:35 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

void	draw(t_vals *vals, int x, int y)
{
	t_point	p1;
	t_point	p2;

	p1 = addratio(setpoint(x, y, vals->array[y][x], vals->array[y][x]),
		vals->map_ratio);
	if (x < vals->array_width - 1)
	{
		p2 = addratio(setpoint(x + 1, y, vals->array[y][x + 1],
			vals->array[y][x + 1]), vals->map_ratio);
		create_line(vals, p1, p2);
	}
	if (y < vals->array_height - 1)
	{
		p2 = addratio(setpoint(x, y + 1, vals->array[y + 1][x],
			vals->array[y + 1][x]), vals->map_ratio);
		create_line(vals, p1, p2);
	}
	return ;
}

void	drawmap(t_vals *vals)
{
	int		x;
	int		y;

	y = 0;
	while (y < vals->array_height)
	{
		x = 0;
		while (x < vals->array_width)
		{
			draw(vals, x, y);
			x++;
		}
		y++;
	}
}

void	drawlow(t_vals *vals, t_point p1, t_point p2)
{
	t_linecalc	low;

	low = set_low(p1, p2);
	while (p1.x != p2.x)
	{
		p1.color = interpolate_color(p1.color, p2.color, low.interpolator.div);
		vals->point = get_iso(p1, vals);
		put_pixel(vals);
		if (low.err > 0)
		{
			p1.y += low.inc;
			low.err += 2 * (low.dy - low.dx);
		}
		else
			low.err += 2 * low.dy;
		p1.x += low.inc;
		low.interpolator.div += 1 / low.interpolator.step;
	}
	return ;
}

void	drawhigh(t_vals *vals, t_point p1, t_point p2)
{
	t_linecalc	high;

	high = set_high(p1, p2);
	while (p1.y != p2.y)
	{
		p1.color = interpolate_color(p1.color, p2.color, high.interpolator.div);
		vals->point = get_iso(p1, vals);
		put_pixel(vals);
		if (high.err > 0)
		{
			p1.x += high.inc;
			high.err += 2 * (high.dx - high.dy);
		}
		else
			high.err += 2 * high.dx;
		p1.y += high.inc;
		high.interpolator.div += 1 / high.interpolator.step;
	}
	return ;
}
