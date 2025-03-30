/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:58:01 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/30 21:58:41 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

void	vals_del(t_vals *vals)
{
	int	*insidelens;
	int	i;

	if (!vals)
		return ;
	if (vals->array)
	{
		i = 0;
		insidelens = (int *) ft_calloc(vals->map.array_height, sizeof(int));
		while (i < vals->map.array_height)
			insidelens[i++] = vals->map.array_width;
		del_3d_array((void ***) vals->array, vals->map.array_height,
			insidelens);
		ft_del(insidelens);
	}
	return ;
}

void	mlx_del(t_vals *vals)
{
	vals_del(vals);
	if (!vals)
		return ;
	if (!vals->array)
	{
		vals->mlx.mlxptr = NULL;
		vals->mlx.img = NULL;
		vals->mlx.win = NULL;
	}
	if (vals->mlx.mlxptr && vals->mlx.win)
		mlx_destroy_window(vals->mlx.mlxptr, vals->mlx.win);
	if (vals->mlx.mlxptr && vals->mlx.img)
		mlx_destroy_image(vals->mlx.mlxptr, vals->mlx.img);
	if (vals->mlx.mlxptr)
	{
		mlx_destroy_display(vals->mlx.mlxptr);
		free(vals->mlx.mlxptr);
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
