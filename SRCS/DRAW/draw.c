/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:49:03 by mzaian            #+#    #+#             */
/*   Updated: 2025/04/08 13:35:12 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

void	draw(t_vals *vals, int x, int y)
{
	t_point	p1;
	t_point	p2;

	p1 = get_iso(addratio(setpoint(x, y, vals), vals->map.map_ratio,
				vals->map.scale), vals);
	if (x < vals->map.array_width - 1)
	{
		p2 = get_iso(addratio(setpoint(x + 1, y, vals), vals->map.map_ratio,
					vals->map.scale), vals);
		create_line(vals, p1, p2);
	}
	if (y < vals->map.array_height - 1)
	{
		p2 = get_iso(addratio(setpoint(x, y + 1, vals), vals->map.map_ratio,
					vals->map.scale), vals);
		create_line(vals, p1, p2);
	}
	return ;
}

void	drawmap(t_vals *vals)
{
	int		x;
	int		y;

	y = 0;
	while (y < vals->map.array_height)
	{
		x = 0;
		while (x < vals->map.array_width)
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
		vals->point = p1;
		vals->point.color = interpolate_color(p1.color, p2.color,
				low.interpolator.div);
		if (p1.x >= 0 && p1.x < vals->mlx.screen_width
			&& p1.y >= 0 && p1.y < vals->mlx.screen_height)
			put_pixel(vals);
		if (low.err > 0)
		{
			p1.y += low.inc;
			low.err += 2 * (low.dy - low.dx);
		}
		else
			low.err += 2 * low.dy;
		p1.x += 1;
		low.interpolator.div += (float) 1 / low.dx;
	}
	return ;
}

void	drawhigh(t_vals *vals, t_point p1, t_point p2)
{
	t_linecalc	high;

	high = set_high(p1, p2);
	while (p1.y != p2.y)
	{
		vals->point = p1;
		vals->point.color = interpolate_color(p1.color, p2.color,
				high.interpolator.div);
		if (p1.x >= 0 && p1.x < vals->mlx.screen_width
			&& p1.y >= 0 && p1.y < vals->mlx.screen_height)
			put_pixel(vals);
		if (high.err > 0)
		{
			p1.x += high.inc;
			high.err += 2 * (high.dx - high.dy);
		}
		else
			high.err += 2 * high.dx;
		p1.y += 1;
		high.interpolator.div += (float) 1 / high.dy;
	}
	return ;
}
