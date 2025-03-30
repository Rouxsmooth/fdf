/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:48:40 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/29 23:17:14 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

int	mlx_close(t_vals *vals)
{
	quit(0, vals);
	return (0);
}

int	move_world(t_vals *vals, t_press pressing)
{
	if (pressing.a)
		vals->x_offset -= 0.25 * vals->map_ratio;
	if (pressing.d)
		vals->x_offset += 0.25 * vals->map_ratio;
	if (pressing.w)
		vals->y_offset -= 0.25 * vals->map_ratio;
	if (pressing.s)
		vals->y_offset += 0.25 * vals->map_ratio;
	return (0);
}

int	reset_map(t_vals *vals)
{
	vals->x_offset = 0;
	vals->y_offset = 0;
	vals->map_ratio = vals->base_map_ratio;
	vals->already_drew = 0;
	return (0);
}
