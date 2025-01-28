/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:02:27 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/28 01:30:43 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

int	array_loop(char *curr_line, char ***array, int i)
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

char	***get_array(int fd, t_vals *vals, char ***array)
{
	char	*curr_line;
	int		i;

	curr_line = get_next_line(fd);
	if (!array || !*array || !curr_line)
		return ((close(fd), ft_del(array), ft_del(curr_line), quit("Allocation error", vals)), NULL);
	i = 0;
	while (i < vals->y)
	{
		if (array_loop(curr_line, array, i) == -1)
			return ((close(fd), ft_del(curr_line)), NULL);
		curr_line = get_next_line(fd);
		if (!array || !*array)
			return ((close(fd), ft_del(array), ft_del(curr_line), quit("Allocation error", vals)), NULL);
		i++;
	}
	close(fd);
	return (array);
}

int	parse_loop(int fd, t_vals *vals)
{
	size_t	item_count;
	char	*curr_line;

	curr_line = get_next_line(fd);
	if (!curr_line)
		quit("Allocation error", vals);
	while (curr_line)
	{
		item_count = get_itemcount(curr_line);
		if ((int) item_count != vals->x && vals->y != 0)
			return (ft_del(curr_line), -1);
		vals->x = item_count;
		curr_line = get_next_line(fd);
		vals->y++;
	}
	return (ft_del(curr_line), 1);
}

char	***map_parser(char *map, t_vals *vals)
{
	int		fd;

	fd = get_map(map);
	if (fd == -1)
		return (display_error("Map not found."), NULL);
	if (fd == -2)
		return (NULL);
	vals->y = 0;
	if (parse_loop(fd, vals) == -1)
	{
		close(fd);
		quit("Allocation error", vals);
	}
	close(fd);
	fd = get_map(map);
	return (get_array(fd, vals, create_array(vals)));
}
