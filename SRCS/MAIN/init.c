/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:57:23 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/29 23:15:26 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

void	init_vals(t_vals *vals, char *title)
{
	vals->array_height = 0;
	vals->array_width = 0;
	vals->array = map_parser(title, vals);
	if (!(vals->array))
		quit("Parsing error!", vals);
	vals->already_drew = 0;
	vals->mlx = mlx_init();
	mlx_get_screen_size(vals->mlx, &(vals->width), &(vals->height));
	vals->height *= 0.9;
	vals->width *= 0.95;
	vals->title = set_title(title);
	if (ft_strcmp(title, vals->title))
		ft_del((void *)vals->title);
	vals->base_map_ratio = ft_min(vals->height / vals->array_height,
			vals->width / vals->array_width) * 0.5;
	vals->map_ratio = vals->base_map_ratio;
	vals->max_map_ratio = -10 * log(4) + 450;
	vals->min_map_ratio = vals->map_ratio / 4;
	vals->x_offset = 0;
	vals->y_offset = 0;
	vals->win = mlx_new_window(vals->mlx, vals->width, vals->height,
			vals->title);
	vals->img = mlx_new_image(vals->mlx, vals->width, vals->height);
	vals->pressing = (t_press){0};
	vals->point = (t_point){0};
}
