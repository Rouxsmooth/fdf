/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:48:43 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/21 11:49:58 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

int	loop(t_vals *vals)
{
	int	i = 0;
	while (i < 600)
	{
		vals->point.x = i;
		vals->point.y = i/2;
		vals->point.color = 0xFFFFFF;
		put_pixel(vals);
		i++;
		ft_printf("x'%d' y'%d'\n", vals->point.x, vals->point.y);
	}
	while (1)
		;
	// draw_map(vals);
	//map draw and events
	return (1);
}

void	hooks_loop(t_vals *vals)
{
	mlx_hook(vals->win, 17, 0, mlx_close, vals);
	mlx_hook(vals->win, 3, 1L<<1, key_release, vals);
	mlx_loop_hook(vals->mlx, loop, vals);
	mlx_loop(vals->mlx);
}
