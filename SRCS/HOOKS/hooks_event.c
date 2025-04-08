/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:48:40 by mzaian            #+#    #+#             */
/*   Updated: 2025/04/08 13:47:00 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

int	mlx_close(t_vals *vals)
{
	quit(0, vals);
	return (0);
}

int	change_scale(t_vals *vals, int keycode)
{
	if (keycode == K_PLUS)
	{
		if (vals->map.scale < 1.0)
			vals->map.scale += 0.05;
	}
	if (keycode == K_MINUS)
	{
		if (vals->map.scale - 0.05 >= 0.01)
			vals->map.scale -= 0.05;
		else
			vals->map.scale = 0.01;
	}
	vals->already_drew = 0;
	return (0);
}

int	move_world(t_vals *vals, t_press pressing)
{
	if (pressing.a)
		vals->x_offset -= (float)(0.25 * vals->map.map_ratio);
	if (pressing.d)
		vals->x_offset += (float)(0.25 * vals->map.map_ratio);
	if (pressing.w)
		vals->y_offset -= (float)(0.25 * vals->map.map_ratio);
	if (pressing.s)
		vals->y_offset += (float)(0.25 * vals->map.map_ratio);
	return (0);
}

int	reset_map(t_vals *vals)
{
	vals->x_offset = 0;
	vals->y_offset = 0;
	vals->map.map_ratio = vals->map.base_map_ratio;
	vals->already_drew = 0;
	vals->map.scale = 0.1;
	return (0);
}
