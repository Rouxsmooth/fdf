/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:44:06 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/30 22:00:11 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

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
