/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:35:22 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/09 16:01:34 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	del_window(t_vals **window)
{
	free((*window)->title);
	mlx_destroy_window((*window)->mlx, (*window)->mlx_window);
	//del mlx_window, image, link etc
}

int	parse_loop(int fd, t_vals *window)
{
	size_t	prev_count;
	size_t	item_count;
	int		i;
	char	*curr_line;

	window->y = 0;
	curr_line = get_next_line(fd);
	while (curr_line)
	{
		item_count = 1;
		i = ft_strlen(curr_line) - 1;
		while (i >= 0)
		{
			if (curr_line[i] == ' ' && curr_line[i + 1])
				item_count++;
			i--;
		}
		prev_count = item_count;
		if (item_count != prev_count)
			return (ft_del(&curr_line), -1);
		curr_line = get_next_line(fd);
		window->y++;
	}
	window->x = item_count;
	return (ft_del(&curr_line), 1);
}

int	map_parser(char *map, t_vals *window)
{
	int		fd;
	char	*path;

	path = ft_strjoin("maps/test_maps/", map);
	fd = open(path, O_RDONLY);
	ft_del(&path);
	if (parse_loop(fd, window) == -1)
		return (close(fd), -1);
	close(fd);
	window->title = map;
	return (1);
}

int	main(int argc, char **argv)
{
	t_vals	*window;

	window = ft_calloc(1, sizeof(t_vals));
	if (argc != 2)
		return (display_error(ft_ternary("Map missing!", "Too much parameters",
			argc < 2)));
	if (map_parser(argv[1], window) == -1)
		return (display_error("Parsing error!"));
	window->mlx = mlx_init();
	ft_printf("%d %d %s\n", window->x, window->y, window->title);
	window->mlx_window = mlx_new_window(window->mlx, 2560, 1440, window->title);
	mlx_loop(window->mlx);
	return (del_window(&window), 1);
}