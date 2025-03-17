/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:48:43 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/17 10:08:31 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

int	loop(t_vals *vals)
{
	//map draw and events
}

void	hooks_loop(t_vals *vals)
{
	mlx_hook(vals->win, 17, 0, mlx_close, vals);
	mlx_hook(vals->win, 3, 1L<<1, key_release, vals);
	mlx_loop_hook(vals->mlx, loop, vals);
	mlx_loop(vals->mlx);
}
