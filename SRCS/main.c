/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:35:22 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/30 11:46:52 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	vals_del(t_vals *vals)
{
	printf("deleting array...\n");
	if (vals->array)
		del_3d_array((void ***) vals->array, vals->y);
	//printf("%s. destroying window...\n", *(vals->array) ? "not deleted array" : "destroyed array");
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
	return (ft_del(vals));
}
//del mlx_vals, image, link etc
//mlx clear is mlx destroy vals -> mlx destroy img -> mlx destroydisplay 
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
		quit("Parsing error!", vals);
	vals->mlx = mlx_init();
	vals->width = 668;
	vals->height = 384;
	vals->title = set_title(argv[1]);
	vals->win = mlx_new_window(vals->mlx, vals->width, vals->height,
				vals->title);
	if (ft_strcmp(argv[1], vals->title))
		ft_del((void *)vals->title);
	vals->img = mlx_new_image(vals->mlx, vals->width, vals->height);
	hooks_loop(vals);
	return (0);
}
