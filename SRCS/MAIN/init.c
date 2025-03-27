/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:57:23 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/27 22:12:03 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

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
	vals.height *= 0.9;
	vals.width *= 0.95;
	vals.title = set_title(title);
	if (ft_strcmp(title, vals.title))
		ft_del((void *)vals.title);
	vals.map_ratio = ft_min(vals.height / vals.array_height,
			vals.width / vals.array_width) * 0.5;
	vals.win = mlx_new_window(vals.mlx, vals.width, vals.height,
			vals.title);
	vals.img = mlx_new_image(vals.mlx, vals.width, vals.height);
	vals.point = (t_point){0};
	return (vals);
}
