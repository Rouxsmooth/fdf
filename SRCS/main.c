/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:35:22 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/09 11:19:50 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	del_window(t_vals **window)
{
	free((*window)->title);
	//del mlx_window, link etc
}

int	*map_parser(char *map, t_vals *window)
{
	size_t	curr_len;
	size_t	prev_len;
	char	*curr_line;
	int		fd;

	fd = open(map, O_RDONLY);
	curr_line = get_next_line(fd);
	curr_len = ft_strlen(curr_line);
	window->title = map;
	window->x = curr_len;
	window->y = 0;
	while (curr_line)
	{
		prev_len = curr_len;
		curr_len = ft_strlen(curr_line);
		if (curr_len != prev_len)
			return (ft_del(&curr_line), -1);
		curr_line = get_next_line(fd);
		window->y++;
	}
	return ((ft_del(curr_line), close(fd)), 1);
}

int	main(int argc, char **argv)
{
	t_vals	*window;

	if (argc != 2)
		return (display_error(ft_ternary("Map missing!", "Too much parameters",
			argc < 2)));
	if (map_parser(argv[1], window) == -1)
		return (display_error("Parsing error!"));
	window->mlx = mlx_init();
}