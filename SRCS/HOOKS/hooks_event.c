/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:48:40 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/27 18:56:47 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

int	mlx_close(t_vals *vals)
{
	quit(0, vals);
	return (0);
}

// ft_printf("code : %d | searched code %d\n", keycode, K_ESCAPE);
int	key_release(int keycode, t_vals *vals)
{
	if (keycode == K_ESCAPE)
		mlx_close(vals);
	return (0);
}
