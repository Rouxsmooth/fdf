/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:44:06 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/27 23:42:13 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

int	interpolate_color(int color1, int color2, float div)
{
	int	red_interpolated;
	int	green_interpolated;
	int	blue_interpolated;

	red_interpolated = (((color2 >> 16) & 0xFF) - ((color1 >> 16) & 0xFF))
		* div + ((color1 >> 16) & 0xFF);
	green_interpolated = (((color2 >> 8) & 0xFF) - ((color1 >> 8) & 0xFF))
		* div + ((color1 >> 8) & 0xFF);
	blue_interpolated = ((color2 & 0xFF) - (color1 & 0xFF))
		* div + (color1 & 0xFF);
	return ((red_interpolated << 16) | (green_interpolated << 8)
		| blue_interpolated);
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

t_linecalc	set_low(t_point p1, t_point p2)
{
	t_linecalc	low;

	low.dx = p2.x - p1.x;
	low.dy = p2.y - p1.y;
	low.inc = 1;
	if (low.dy < 0)
		low.inc = -1;
	low.dy *= low.inc;
	low.interpolator.step = low.dx;
	low.interpolator.div = 0.0;
	low.err = 2 * low.dy - low.dx;
	return (low);
}

t_linecalc	set_high(t_point p1, t_point p2)
{
	t_linecalc	high;

	high.dx = p2.x - p1.x;
	high.dy = p2.y - p1.y;
	high.inc = 1;
	if (high.dx < 0)
		high.inc = -1;
	high.dx *= high.inc;
	high.interpolator.step = high.dy;
	high.interpolator.div = 0.0;
	high.err = 2 * high.dx - high.dy;
	return (high);
}

void	create_line(t_vals *vals, t_point p1, t_point p2)
{
	// p1 = get_iso(p1, vals);
	// p2 = get_iso(p2, vals);
	// ft_printf(" in screen size %d %d\n", vals->width, vals->height);
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
