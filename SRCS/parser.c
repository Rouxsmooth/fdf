/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:02:27 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/24 16:09:53 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int	array_loop(t_vals *window, char *curr_line, char ***array, int i)
{
	int	start;
	int	end;
	int	k;

	end = 0;
	k = 0;
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
			return (-1);
		k++;
		end++;
	}
	return (1);
}

char	***get_array(int fd, t_vals *window, int i, char ***array)
{
	int		k;
	int		end;
	char	*curr_line;

	curr_line = get_next_line(fd);
	if (!array || !*array || !curr_line)
		return ((ft_del(array), ft_del(curr_line), alloc_error()), NULL);
	while (i < window->y)
	{
		if (array_loop(window, curr_line, array, i) == -1)
			return ((clear_3d_array(array), alloc_error()), NULL);
		curr_line = get_next_line(fd);
		i++;
	}
	return (ft_del(curr_line), array);
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
