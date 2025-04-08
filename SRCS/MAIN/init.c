/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:57:23 by mzaian            #+#    #+#             */
/*   Updated: 2025/04/08 13:36:41 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

void	init_map(t_map *map, t_vals *vals)
{
	map->base_map_ratio = ft_floatmax(
			ft_floatmin(vals->mlx.screen_height / map->array_height,
				vals->mlx.screen_width / map->array_width) * 0.5, 1);
	map->map_ratio = map->base_map_ratio;
	map->max_map_ratio = -10 * log(4) + 450;
	map->min_map_ratio = ft_floatmax(map->map_ratio / 4, 1);
	map->scale = 0.1;
	get_extremums(vals);
	return ;
}

void	init_mlx(t_mlx *mlx, char *title)
{
	mlx->mlxptr = mlx_init();
	mlx_get_screen_size(mlx->mlxptr, &(mlx->screen_width),
		&(mlx->screen_height));
	mlx->screen_height *= 0.9;
	mlx->screen_width *= 0.95;
	mlx->win = mlx_new_window(mlx->mlxptr, mlx->screen_width,
			mlx->screen_height, title);
	mlx->img = mlx_new_image(mlx->mlxptr, mlx->screen_width,
			mlx->screen_height);
	return ;
}

void	init_vals(t_vals *vals, char *title)
{
	vals->map = (t_map){0};
	vals->point = (t_point){0};
	vals->array = map_parser(title, vals);
	if (!(vals->array))
		quit("Parsing error!", vals);
	vals->map.title = set_title(title);
	if (ft_strcmp(title, vals->map.title))
		ft_del((void *)vals->map.title);
	init_mlx(&(vals->mlx), vals->map.title);
	init_map(&(vals->map), vals);
	vals->x_offset = 0.0f;
	vals->y_offset = 0.0f;
	vals->already_drew = 0;
	vals->pressing = (t_press){0};
	return ;
}
