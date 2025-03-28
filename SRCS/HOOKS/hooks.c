/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:48:43 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/28 15:14:38 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

int	loop(t_vals *vals)
{
	int	temp;

	if (!vals->already_drew)
	{
		
		ft_bzero(mlx_get_data_addr(vals->img, &temp, &temp, &temp), vals->width * vals->height * sizeof(int));
		drawmap(vals);
		mlx_put_image_to_window(vals->mlx, vals->win, vals->img, 0, 0);
		vals->already_drew = 1;
	}
	return (1);
}

void	hooks_loop(t_vals *vals)
{
	mlx_hook(vals->win, 17, 0, mlx_close, vals);
	mlx_hook(vals->win, 4, 1L << 2, mouse_down, vals);
	mlx_hook(vals->win, 3, 1L << 1, key_release, vals);
	mlx_loop_hook(vals->mlx, loop, vals);
	mlx_loop(vals->mlx);
}
