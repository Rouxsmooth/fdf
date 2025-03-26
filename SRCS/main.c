/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:35:22 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/26 16:06:18 by mzaian           ###   ########.fr       */
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

t_vals	init_vals(char *title)
{
	t_vals	vals;

	vals.array_height = 0;
	vals.array_width = 0;
	vals.array = map_parser(title, &vals);
	if (!(vals.array))
		quit("Parsing error!", &vals);
	vals.already_drew = 0;
	vals.mlx = mlx_init();
	mlx_get_screen_size(vals.mlx, &(vals.width), &(vals.height));
	vals.height *= 0.92;
	vals.width *= 0.95;
	vals.title = set_title(title);
	if (ft_strcmp(title, vals.title))
		ft_del((void *)vals.title);
	vals.map_ratio = ft_min(vals.height / vals.array_height * 0.75,
			vals.width / vals.array_width * 0.75);
	vals.win = mlx_new_window(vals.mlx, vals.width, vals.height,
			vals.title);
	vals.img = mlx_new_image(vals.mlx, vals.width, vals.height);
	vals.point = (t_point) {0};
	return (vals);
}

int	main(int argc, char **argv)
{
	t_vals	vals;

	if (argc != 2)
		return (display_error(ft_ternary("Map missing!", "Too much parameters",
					argc < 2)));
	vals = init_vals(argv[1]);
	hooks_loop(&vals);
	return (0);
}
