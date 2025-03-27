/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:58:01 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/27 18:58:04 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

void	vals_del(t_vals *vals)
{
	int	*insidelens;
	int	i;

	if (vals->array)
	{
		i = 0;
		insidelens = (int *) ft_calloc(vals->array_height, sizeof(int));
		while (i < vals->array_height)
			insidelens[i++] = vals->array_width;
		del_3d_array((void ***) vals->array, vals->array_height, insidelens);
		ft_del(insidelens);
	}
	return ;
}

void	mlx_del(t_vals *vals)
{
	vals_del(vals);
	if (vals->mlx && vals->win)
		mlx_destroy_window(vals->mlx, vals->win);
	if (vals->mlx && vals->img)
		mlx_destroy_image(vals->mlx, vals->img);
	if (vals->mlx)
	{
		mlx_destroy_display(vals->mlx);
		free(vals->mlx);
	}
	return ;
}

void	quit(char *error_msg, t_vals *vals)
{
	mlx_del(vals);
	if (error_msg)
		display_error(error_msg);
	exit(0);
}
