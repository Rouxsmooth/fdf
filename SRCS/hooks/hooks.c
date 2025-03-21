/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:48:43 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/21 14:17:35 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

int	loop(t_vals *vals)
{
	draw_map(vals);
	mlx_put_image_to_window(vals->mlx, vals->win, vals->img, 0, 0);
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
