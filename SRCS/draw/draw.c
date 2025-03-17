/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:49:03 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/17 11:10:18 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

void	draw_map(t_vals *vals)
{
	t_point	start;

	start.x = vals->y
	while (start.x)
	{
		
		start.x--;
	}
}
void	put_pixel(t_vals *vals)
{
	int	*pixel;
	int	temp;
	int	size_line;

	pixel = (int *) mlx_get_data_addr(vals->img, &temp, &size_line, &temp);
	pixel[vals->point.y * vals->width + vals->point.x] = vals->point.color;
}
