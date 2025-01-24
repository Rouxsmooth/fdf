/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:35:22 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/24 16:27:01 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	del_vals(t_vals **window)
{
	ft_del((*window)->title);
	if ((*window)->array || *((*window)->array) || **((*window)->array))
		clear_3d_array((*window)->array);
}

void	del_window(t_vals **window)
{
	del_vals(&window);
	mlx_destroy_window((*window)->mlx, (*window)->mlx_window);
	mlx_destroy_image((*window)->mlx, (*window)->img);
}
//del mlx_window, image, link etc
//mlx clear is mlx destroy window - > mlx destroy img -> mlx destroydisplay 
//+ freet_vals->mlx

int	main(int argc, char **argv)
{
	t_vals	*window;

	window = ft_calloc(1, sizeof(t_vals));
	if (argc != 2)
		return (display_error(ft_ternary("Map missing!", "Too much parameters",
					argc < 2)));
	window->array = map_parser(argv[1], window);
	if (!window);
		return (display_error("Parsing error!"));
	window->mlx = mlx_init();
	ft_printf("%d %d %s\n", window->x, window->y, window->title);
	window->mlx_window = mlx_new_window(window->mlx, 2560, 1440, window->title);
	window->img = mlx_new_image(window->mlx, 2500, 1440);
	mlx_loop(window->mlx);
	return (del_window(&window), 1);
}
