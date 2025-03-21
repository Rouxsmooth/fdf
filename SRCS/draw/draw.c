/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:49:03 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/21 14:28:13 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

void	put_pixel(t_vals *vals)
{
	int	*pixel;
	int	temp;
	int	size_line;

	pixel = (int *) mlx_get_data_addr(vals->img, &temp, &size_line, &temp);
	pixel[vals->point.y * vals->width + vals->point.x] = vals->point.color;
}

unsigned int	get_color(char *hexinstr)
{
	int				i;
	char			*base;
	unsigned int	nbr;
	int				start;

	nbr = 0;
	start = ft_strstrindex(hexinstr, "0x") + 2;
	if (start == 1)
		return (0xFFFFFF);
	if (ft_strchr(&hexinstr[start], 'a') || ft_strchr(&hexinstr[start], 'b')
		|| ft_strchr(&hexinstr[start], 'c') || ft_strchr(&hexinstr[start], 'd')
		|| ft_strchr(&hexinstr[start], 'e') || ft_strchr(&hexinstr[start], 'f'))
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	while (hexinstr[start])
	{
		nbr *= 16;
		i = 0;
		while (hexinstr[start] != base[i])
			i++;
		nbr += i;
		start++;
	}
	return (nbr);
}

void	draw_line(t_vals *vals, t_point p1, t_point p2)
{
	int	dx;
	int	dy;
	int	err;
	int	e2;

	dx = ft_abs(p2.x - p1.x);
	dy = -ft_abs(p2.y - p1.y);
	err = dx + dy;
	while (1)
	{
		vals->point = p1;
		put_pixel(vals);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			if (p1.x < p2.x)
				p1.x += 1;
			else
				p1.x -= 1;
		}
		if (e2 <= dx)
		{
			err += dx;
			if (p1.y < p2.y)
				p1.y += 1;
			else
				p1.y -= 1;
		}
	}
}

void	draw_map(t_vals *vals)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	y = 0;
	while (y < vals->y - 1)
	{
		x = 0;
		while (x < vals->x - 1)
		{
			p1.x = x;
			p1.y = y;
			p1.z = ft_atoi(vals->array[y][x]);
			p1.color = get_color(vals->array[y][x]);
			if (x < vals->x - 1)
			{
				p2.x = x + 1;
				p2.y = y;
				p2.z = ft_atoi(vals->array[y][x + 1]);
				p2.color = get_color(vals->array[y + 1][x]);
				draw_line(vals, p1, p2);
			}
			if (y < vals->y - 1)
			{
				p2.x = x;
				p2.y = y + 1;
				p2.z = ft_atoi(vals->array[y + 1][x]);
				p2.color = get_color(vals->array[y + 1][x]);
				draw_line(vals, p1, p2);
			}
			x++;
		}
		y++;
	}
}
