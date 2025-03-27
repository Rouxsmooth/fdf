/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:47:32 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/27 19:57:31 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

void	put_pixel(t_vals *vals)
{
	int	*pixel;
	int	temp;
	int	size_line;

	// ft_printf("%d %d %d : %d\n", vals->point.y, vals->width, vals->point.x, vals->point.y * vals->width + vals->point.x);
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

t_point	get_iso(t_point point, t_vals *vals)
{
	int prev_x;
	int prev_y;

	prev_x = point.x;
	prev_y = point.y;
	point.x = (prev_x - prev_y) * cos(30 * M_PI / 180) + (vals->array_width / 4  * vals->map_ratio);
	point.y = (prev_x + prev_y) * sin(30 * M_PI / 180) - point.z + (vals->array_height / 4 * vals->map_ratio);
	if (point.z != 0 && point.z != 10)
	{
		printf("z vaut %d\n", point.z);
		while (1)
			;
	}
	return (point);
}
