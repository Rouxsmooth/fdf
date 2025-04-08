/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colored_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:36:14 by mzaian            #+#    #+#             */
/*   Updated: 2025/04/06 17:27:58 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

void	ft_color_chars_but(int fd, char *msg, int (keep)(int), int color)
{
	int		i;

	i = 0;
	while (msg[i])
	{
		if (!keep(msg[i]))
			start_colored_output(fd, color);
		while (msg[i] && !keep(msg[i]))
			ft_putchar_fd(msg[i++], fd);
		close_colored_output(fd);
		while (msg[i] && keep(msg[i]))
			ft_putchar_fd(msg[i++], fd);
	}
	return (close_colored_output(fd));
}

int	colorcode_by_str(char *color)
{
	if (color)
	{
		if (!ft_strcmp(color, "red"))
			return (31);
		else if (!ft_strcmp(color, "green"))
			return (32);
		else if (!ft_strcmp(color, "yellow"))
			return (93);
		else if (!ft_strcmp(color, "blue"))
			return (34);
		else if (!ft_strcmp(color, "magenta"))
			return (95);
		else if (!ft_strcmp(color, "cyan"))
			return (36);
		else if (!ft_strcmp(color, "white"))
			return (37);
		else if (!ft_strcmp(color, "orange"))
			return (91);
	}
	return ((start_colored_output(2, 31),
			ft_putstr_fd("Unknown color string\n", 2),
			close_colored_output(2)), 0);
}

void	start_colored_output(int fd, int colorcode)
{
	return (ft_putstr_fd("\e[", fd), ft_putnbr_fd(colorcode, fd),
		ft_putstr_fd(";1m", fd));
}

void	close_colored_output(int fd)
{
	return (ft_putstr_fd("\e[0m", fd));
}
// a few color codes :
// red  \e[31;1m
// green  \e[32;1m
// yellow  \e[33;1m
// blue  \e[34;1m
// magenta  \e[35;1m
// cyan  \e[36;1m
// white  \e[37;1m
// grey   \e[90;1m
// bright red  \e[91;1m
// bright green  \e[92;1m
// bright yellow  \e[93;1m
// bright blue  \e[94;1m
// bright magenta  \e[95;1m
// bright cyan  \e[96;1m
// bright white  \e[97;1m
// 40++ == background color
// 53 == entitle