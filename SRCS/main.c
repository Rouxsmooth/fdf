/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:35:22 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/24 13:53:21 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

#include <stdio.h>

void	del_window(t_vals **window)
{
	free((*window)->title);
	mlx_destroy_window((*window)->mlx, (*window)->mlx_window);
	//del mlx_window, image, link etc
}

int	alloc_error(void)
{
	return (display_error("Allocation error"), -1);
}

void	clear_array(char ***array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			free(array[i][j]);
			j++;
		}
		i++;
	}
	return (free(array));
}

char	***create_array(t_vals *window)
{
	char	***array;
	int	i;

	array = (char ***) ft_calloc(window->y + 1, sizeof(char **));
	i = 0;
	while (i < window->y)
	{
		array[i] = (char **) ft_calloc(window->x + 1, sizeof(char **));
		i++;
	}
	return (array);
}

void	print_array(char ***array, t_vals *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->y)
	{
		j = 0;
		ft_printf("line : %d\t", i);
		while (j < window->x)
			ft_printf("'%s' ", array[i][j++]);
		ft_printf("\n");
		i++;
	}
}

char	***get_array(int fd, t_vals *window, int i, char ***array)
{
	int		k;
	int		start;
	int		end;
	char	*curr_line;

	curr_line = get_next_line(fd);
	if (!array || !*array || !curr_line)
		return ((ft_del(array), ft_del(curr_line), alloc_error()), NULL);
	while (i < window->y)
	{
		k = 0;
		end = 0;
		while (curr_line[end])
		{
			if (end == 0 && curr_line[end] && curr_line[end] == ' ')
				end++;
			while (curr_line[end] && curr_line[end] == ' ')
				end++;
			start = end;
			while (curr_line[end] && curr_line[end] != ' ')
				end++;
			if (!curr_line[end])
				end--;
			array[i][k] = ft_substr(curr_line, start, end - start);
			if (!array[i][k])
				return ((clear_3d_array(array), alloc_error()), NULL);
			k++;
			end++;
		}
		curr_line = get_next_line(fd);
		i++;
	}
	print_array(array, window);
	return (ft_del(curr_line), array);
}

int	get_itemcount(char *curr_line)
{
	int	item_count;
	int	i;

	item_count = 1;
	i = ft_strlen(curr_line) - 1;
	if (curr_line[i] == '\n')
		i--;
	if (curr_line[i] == ' ')
	{
		item_count--;
		while (curr_line[i] == ' ')
			i--;
	}
	while (i >= 0)
	{
		while (curr_line[i] && curr_line[i] == ' ' && curr_line[i + 1])
			i--;
		if (curr_line[i + 1] == ' ' && curr_line[i])
			item_count++;
		while (curr_line[i] && !curr_line[i] == ' ')
			i--;
		i--;
	}
	return (item_count);
}

int	parse_loop(int fd, t_vals *window)
{
	size_t	item_count;
	int		i;
	char	*curr_line;

	curr_line = get_next_line(fd);
	while (curr_line)
	{
		item_count = get_itemcount(curr_line);
		if (item_count != window->x && window->y != 0)
			return (ft_del(curr_line), -1);
		window->x = item_count;
		curr_line = get_next_line(fd);
		window->y++;
	}
	return (ft_del(curr_line), 1);
}

char	*set_title(char *map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (map[i] == '.' && map[i + 1] == 'f' && map[i + 2] == 'd'
			&& map[i] + 3 == 'f')
			return (ft_substr(map, 0, i));
		i++;
	}
	return (map);
}

int	get_map(char *map)
{
	int		fd;
	char	*mappath;

	mappath = ft_strjoin(".maps/", map);
	if (!mappath)
		return (alloc_error(), -2);
	fd = open(mappath, O_RDONLY);
	if (fd != -1)
		return (ft_del(mappath), fd);
	mappath = ft_strjoin(mappath, ".fdf");
	fd = open(mappath, O_RDONLY);
	if (fd != -1)
		return (ft_del(mappath), fd);
	fd = open(map, O_RDONLY);	
	return (ft_del(mappath), fd);
}

char	***map_parser(char *map, t_vals *window)
{
	int		fd;
	char	***array;

	fd = get_map(map);
	if (fd == -1)
		return (display_error("Map not found."), NULL);
	if (fd == -2)
		return (NULL);
	window->y = 0;
	if (parse_loop(fd, window) == -1)
		return (close(fd), NULL);
	close(fd);
	fd = get_map(map);
	array = get_array(fd, window, 0, create_array(window));
	close(fd);
	window->title = set_title(map);
	return (array);
}

int	main(int argc, char **argv)
{
	t_vals	*window;

	window = ft_calloc(1, sizeof(t_vals));
	if (argc != 2)
		return (display_error(ft_ternary("Map missing!", "Too much parameters",
			argc < 2)));
	if (!map_parser(argv[1], window))
		return (display_error("Parsing error!"));
	window->mlx = mlx_init();
	ft_printf("%d %d %s\n", window->x, window->y, window->title);
	window->mlx_window = mlx_new_window(window->mlx, 2560, 1440, window->title);
	mlx_loop(window->mlx);
	return (del_window(&window), 1);
}