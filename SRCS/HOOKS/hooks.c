/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:48:43 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/30 22:02:13 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

int	key_press(int keycode, t_vals *vals)
{
	if (keycode == K_W)
		vals->pressing.w = 1;
	if (keycode == K_S)
		vals->pressing.s = 1;
	if (keycode == K_A)
		vals->pressing.a = 1;
	if (keycode == K_D)
		vals->pressing.d = 1;
	return (0);
}

int	key_release(int keycode, t_vals *vals)
{
	if (keycode == K_ESCAPE)
		mlx_close(vals);
	if (keycode == K_W)
		vals->pressing.w = 0;
	if (keycode == K_S)
		vals->pressing.s = 0;
	if (keycode == K_A)
		vals->pressing.a = 0;
	if (keycode == K_D)
		vals->pressing.d = 0;
	if (keycode == K_SPACE)
		reset_map(vals);
	return (0);
}

int	mouse_down(int mousecode, int mouse_x, int mouse_y, t_vals *vals)
{
	(void) (mouse_x + mouse_y);
	if (mousecode == M_SCROLLUP)
	{
		if (vals->map.map_ratio * 1.03 < vals->map.max_map_ratio)
		{
			vals->y_offset += (vals->map.map_ratio * 1.03 - vals->map.map_ratio)
				* 5.0;
			vals->map.map_ratio *= 1.03;
			vals->already_drew = 0;
		}
	}
	if (mousecode == M_SCROLLDOWN)
	{
		if (vals->map.map_ratio * 0.97 > vals->map.min_map_ratio)
		{
			vals->y_offset -= (vals->map.map_ratio * 0.97 - vals->map.map_ratio)
				* 5.0;
			vals->map.map_ratio *= 0.97;
			vals->already_drew = 0;
		}
	}
	return (0);
}

int	loop(t_vals *vals)
{
	int	temp;

	if (vals->pressing.a || vals->pressing.w
		|| vals->pressing.d || vals->pressing.s)
		vals->already_drew = 0;
	if (!vals->already_drew)
	{
		ft_bzero(mlx_get_data_addr(vals->mlx.img, &temp, &temp, &temp),
			vals->mlx.screen_width * vals->mlx.screen_height * sizeof(int));
		move_world(vals, vals->pressing);
		drawmap(vals);
		mlx_put_image_to_window(vals->mlx.mlxptr, vals->mlx.win,
			vals->mlx.img, 0, 0);
		vals->already_drew = 1;
	}
	return (1);
}

void	hooks_loop(t_vals *vals)
{
	mlx_hook(vals->mlx.win, 17, 0, mlx_close, vals);
	mlx_hook(vals->mlx.win, 4, 1L << 2, mouse_down, vals);
	mlx_hook(vals->mlx.win, 3, 1L << 1, key_release, vals);
	mlx_hook(vals->mlx.win, 2, 1L << 0, key_press, vals);
	mlx_loop_hook(vals->mlx.mlxptr, loop, vals);
	mlx_loop(vals->mlx.mlxptr);
}
