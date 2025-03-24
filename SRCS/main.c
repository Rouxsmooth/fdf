/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:35:22 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/24 13:45:26 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	vals_del(t_vals *vals)
{
	int	*insidelens;
	int	i;

	if (vals->array)
	{
		i = 0;
		insidelens = (int *) ft_calloc(vals->y, sizeof(int));
		while (i < vals->y)
			insidelens[i++] = vals->x;
		del_3d_array((void ***) vals->array, vals->y, insidelens);
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
	return (ft_del(vals));
}

void	quit(char *error_msg, t_vals *vals)
{
	mlx_del(vals);
	if (error_msg)
		display_error(error_msg);
	exit(0);
}

int	ft_min(int i1, int i2)
{
	if (i1 < i2)
		return (i1);
	return (i2);
}

int	main(int argc, char **argv)
{
	t_vals	*vals;

	if (argc != 2)
		return (display_error(ft_ternary("Map missing!", "Too much parameters",
					argc < 2)));
	vals = ft_calloc(1, sizeof(t_vals));
	vals->array = map_parser(argv[1], vals);
	if (!(vals->array))
		quit("Parsing error!", vals);
	vals->mlx = mlx_init();
	mlx_get_screen_size(vals->mlx, &(vals->width), &(vals->height));
	vals->height *= 0.92;
	vals->width *= 0.95;
	vals->map_ratio = ft_min(vals->height / vals->y * 0.75, vals->width / vals->x * 0.75);
	vals->title = set_title(argv[1]);
	vals->win = mlx_new_window(vals->mlx, vals->width, vals->height,
			vals->title);
	if (ft_strcmp(argv[1], vals->title))
		ft_del((void *)vals->title);
	vals->img = mlx_new_image(vals->mlx, vals->width, vals->height);
	hooks_loop(vals);
	return (0);
}
