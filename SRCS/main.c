/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:35:22 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/26 18:36:46 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	vals_del(t_vals *vals)
{
	printf("deleting array...\n");
	if (vals->array || *(vals->array) || **(vals->array))
		clear_3d_array(vals->array);
	printf("deleted array. destroying window...\n");
	return ;
}

void	mlx_del(t_vals *vals)
{
	vals_del(vals);
	if (vals->mlx && vals->win)
		mlx_destroy_window(vals->mlx, vals->win);
	printf("destroyed window. destroying img...\n");
	if (vals->mlx && vals->img)
		mlx_destroy_image(vals->mlx, vals->img);
	printf("destroyed img. destroying display...\n");
	if (vals->mlx)
	{
		mlx_destroy_display(vals->mlx);
		printf("destroyed display. freeing mlx...\n");
		free(vals->mlx);
		printf("freed mlx\n");
	}
	return ;
}
//del mlx_vals, image, link etc
//mlx clear is mlx destroy vals - > mlx destroy img -> mlx destroydisplay 
//+ freet_vals->mlx

void	quit(char *error_msg, t_vals *vals)
{
	mlx_del(vals);
	if (error_msg)
		display_error(error_msg);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_vals	*vals;

	vals = ft_calloc(1, sizeof(t_vals));
	if (argc != 2)
		return (display_error(ft_ternary("Map missing!", "Too much parameters",
					argc < 2)));
	vals->array = map_parser(argv[1], vals);
	if (!(vals->array))
		return (display_error("Parsing error!"));
	vals->mlx = mlx_init();
	vals->width = 1336;
	vals->height = 768;
	vals->win = mlx_new_window(vals->mlx, vals->width, vals->height,
				set_title(argv[1]));
	vals->img = mlx_new_image(vals->mlx, vals->width, vals->height);
	hooks_loop(vals);
	return (0);
}
