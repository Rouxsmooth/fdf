/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:00:24 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/30 22:00:34 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

int	interpolate_color(int color1, int color2, float div)
{
	int	red_interpolated;
	int	green_interpolated;
	int	blue_interpolated;

	red_interpolated = (((color2 >> 16) & 0xFF) - ((color1 >> 16) & 0xFF))
		* div + ((color1 >> 16) & 0xFF);
	green_interpolated = (((color2 >> 8) & 0xFF) - ((color1 >> 8) & 0xFF))
		* div + ((color1 >> 8) & 0xFF);
	blue_interpolated = ((color2 & 0xFF) - (color1 & 0xFF))
		* div + (color1 & 0xFF);
	return ((red_interpolated << 16) | (green_interpolated << 8)
		| blue_interpolated);
}

unsigned int	getcolor_by_height(t_vals *vals, int z)
{
	int	range;
	int	scale;
	int	scaled;

	range = vals->map.highest_z - vals->map.lowest_z;
	if (range == 0)
		return (0xFFFFFF);
	scale = (255 * 3) / range;
	scaled = (z - vals->map.lowest_z) * scale;
	if (scaled < 255)
		return ((scaled << 8) | (255 - scaled));
	if (scaled < 255 * 2)
		return (((scaled - 255) << 16) | (255 << 8));
	return ((255 << 16) | ((255 - (scaled - 255 * 2)) << 8));
}

char	*getbase(char *hexinstr, int start)
{
	if (ft_strchr(&hexinstr[start], 'a') || ft_strchr(&hexinstr[start], 'b')
		|| ft_strchr(&hexinstr[start], 'c') || ft_strchr(&hexinstr[start], 'd')
		|| ft_strchr(&hexinstr[start], 'e') || ft_strchr(&hexinstr[start], 'f'))
		return ("0123456789abcdef");
	return ("0123456789ABCDEF");
}

unsigned int	getcolor(char *hexinstr, t_vals *vals)
{
	int				i;
	char			*base;
	unsigned int	nbr;
	int				start;

	if (!vals->map.has_color)
		return (getcolor_by_height(vals, ft_atoi(hexinstr)));
	start = ft_strstrindex(hexinstr, "0x") + 2;
	if (start == 1)
		return (0xFFFFFF);
	base = getbase(hexinstr, start);
	nbr = 0;
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
