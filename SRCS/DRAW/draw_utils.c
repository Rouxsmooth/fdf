/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:47:32 by mzaian            #+#    #+#             */
/*   Updated: 2025/04/08 13:44:24 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

void	put_pixel(t_vals *vals)
{
	int	*pixel;
	int	temp;
	int	size_line;

	pixel = (int *) mlx_get_data_addr(vals->mlx.img, &temp, &size_line, &temp);
	pixel[(int) vals->point.y * vals->mlx.screen_width + (int) vals->point.x]
		= vals->point.color;
	return ;
}

t_point	addratio(t_point point, int ratio, float scale)
{
	point.x *= ratio;
	point.y *= ratio;
	point.z *= scale;
	return (point);
}

t_point	setpoint(int x, int y, t_vals *vals)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = ft_atoi(vals->array[y][x]);
	point.color = getcolor(vals->array[y][x], vals);
	return (point);
}

t_point	get_iso(t_point point, t_vals *vals)
{
	float	x;
	float	y;

	if (vals->map.map_ratio < 5)
	{
		x = (float)(point.x * vals->map.map_ratio
				- ((float)(vals->map.array_width - 1)
					/ 2.0 * vals->map.map_ratio));
		y = (float)(point.y * vals->map.map_ratio
				- ((float)(vals->map.array_height - 1)
					/ 2.0 * vals->map.map_ratio));
	}
	else
	{
		x = (point.x - (vals->map.array_width - 1) / 2.0 * vals->map.map_ratio);
		y = point.y - (vals->map.array_height - 1) / 2.0 * vals->map.map_ratio;
	}
	point.x = (int)((x - y) * cos(M_PI / 6) + (vals->mlx.screen_width / 2)
			+ vals->x_offset);
	point.y = (int)((x + y) * sin(M_PI / 6) - (point.z * vals->map.map_ratio)
			+ (vals->mlx.screen_height / 2) + vals->y_offset);
	return (point);
}
