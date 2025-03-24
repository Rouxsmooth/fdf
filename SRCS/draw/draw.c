/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:49:03 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/24 13:46:50 by mzaian           ###   ########.fr       */
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

void draw_line(t_vals *vals, t_point p1, t_point p2)
{
	while (p1.x != p2.x || p1.y != p2.y)
	{
		vals->point = p1;
		put_pixel(vals);
		if (p1.x < p2.x)
			p1.x++;
		else if (p1.x > p2.x)
			p1.x--;
		if (p1.y < p2.y)
			p1.y++;
		else if (p1.y > p2.y)
			p1.y--;
	}
	return ;
}

void create_line(t_vals *vals, t_point p1, t_point p2)
{
	int	dx;
	int	dy;
	int	err;

	dx = ft_abs(p2.x - p1.x);
	dy = ft_abs(p2.y - p1.y);
	err = dx - dy;
	p1.x *= vals->map_ratio;
	p1.y *= vals->map_ratio;
	p1.z *= vals->map_ratio;
	p2.x *= vals->map_ratio;
	p2.y *= vals->map_ratio;
	p2.z *= vals->map_ratio; // je dois vraiment regler cette horreur bordel et ajouter ce z au passage.....
	while (p1.x != p2.x || p1.y != p2.y)
	{
		vals->point = p1;
		put_pixel(vals);
		if (2 * err > -dy)
		{
			err -= dy;
			p1.x += ft_intternary(1, -1, p1.x < p2.x);
		}
		if (2 * err < dx)
		{
			err += dx;
			p1.y += ft_intternary(1, -1, p1.y < p2.y);
		}	
	}
	draw_line(vals, p1, p2);
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
				create_line(vals, p1, p2);
			}
			if (y < vals->y - 1)
			{
				p2.x = x;
				p2.y = y + 1;
				p2.z = ft_atoi(vals->array[y + 1][x]);
				p2.color = get_color(vals->array[y + 1][x]);
				create_line(vals, p1, p2);
			}
			x++;
		}
		y++;
	}
}
