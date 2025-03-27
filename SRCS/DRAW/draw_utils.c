/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:47:32 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/27 18:50:38 by mzaian           ###   ########.fr       */
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
	return ;
}

t_point	addratio(t_point point, int ratio)
{
	point.x *= ratio;
	point.y *= ratio;
	point.z *= ratio;
	return (point);
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
