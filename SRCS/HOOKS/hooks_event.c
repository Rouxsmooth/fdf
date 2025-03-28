/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:48:40 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/28 15:16:11 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

int	mlx_close(t_vals *vals)
{
	quit(0, vals);
	return (0);
}

int	key_release(int keycode, t_vals *vals)
{
	if (keycode == K_ESCAPE)
		mlx_close(vals);
	return (0);
}

int	mouse_down(int mousecode, int mouse_x, int mouse_y, t_vals *vals)
{
	(void) (mouse_x + mouse_y);
	if (mousecode == M_SCROLLUP)
	{
		vals->map_ratio *= 1.03;
		vals->already_drew = 0;
	}
	if (mousecode == M_SCROLLDOWN)
	{
		vals->map_ratio *= 0.97;
		vals->already_drew = 0;
	}
	return (0);
}
