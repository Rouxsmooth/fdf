/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:47:32 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/28 14:38:22 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

void	put_pixel(t_vals *vals)
{
	int	*pixel;
	int	temp;
	int	size_line;

	printf("y%f x%f : tot%f\n", vals->point.y, vals->point.x, vals->point.y * vals->width + vals->point.x);
	pixel = (int *) mlx_get_data_addr(vals->img, &temp, &size_line, &temp);
	pixel[(int) vals->point.y * vals->width + (int) vals->point.x] = vals->point.color;
	return ;
}

t_point	addratio(t_point point, int ratio)
{
	point.x *= ratio;
	point.y *= ratio;
	point.z *= 0.09;
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
	
t_point	get_iso(t_point point, t_vals *vals)
{
	float	x;
	float	y;

	x = point.x + (vals->array_width - 1) / 2 * vals->map_ratio;
	y = point.y + (vals->array_height - 1) / 2 * vals->map_ratio;
	point.x = (int) ((x - y) * cos(M_PI / 6) + vals->width / 2);
	point.y = (int) ((x + y) * cos(M_PI / 6) - (point.z * vals->map_ratio)
		+ vals->height / 2);
	return (point);
}
