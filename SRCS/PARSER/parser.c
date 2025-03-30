/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:02:27 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/30 22:03:17 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

int	nl_index(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (i - 1);
	return (-1);
}

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
		return ((close(fd), ft_del(array), ft_del(curr_line),
				quit("Allocation error", vals)), NULL);
	i = 0;
	while (i < vals->map.array_height)
	{
		if (array_loop(curr_line, array, i) == -1)
			return ((close(fd), ft_del(curr_line)), NULL);
		ft_del(curr_line);
		curr_line = get_next_line(fd);
		if (!array || !*array)
			return ((close(fd), ft_del(array), ft_del(curr_line),
					quit("Allocation error", vals)), NULL);
		i++;
	}
	close(fd);
	return (ft_del(curr_line), array);
}

int	parse_loop(int fd, t_vals *vals)
{
	size_t	item_count;
	int		invalid;
	char	*curr_line;

	invalid = 0;
	curr_line = get_next_line(fd);
	if (!curr_line)
		quit("Allocation error", vals);
	while (curr_line)
	{
		item_count = get_itemcount(curr_line);
		if (!vals->map.has_color)
			vals->map.has_color = ft_intternary(1, 0,
					ft_strstr(curr_line, ",0x") != NULL);
		if (((int)item_count != vals->map.array_width
				&& vals->map.array_height != 0) || (nl_index(curr_line) > 0
				&& curr_line[nl_index(curr_line) - 1] == ' '))
			invalid = 1;
		vals->map.array_width = item_count;
		ft_del(curr_line);
		curr_line = get_next_line(fd);
		vals->map.array_height++;
	}
	return (ft_del(curr_line), invalid);
}

char	***map_parser(char *map, t_vals *vals)
{
	int		fd;

	fd = get_map(map);
	if (fd == -1)
		return (vals->array = NULL, display_error("Map not found."), NULL);
	if (fd == -2)
		return (NULL);
	fd = get_map(map);
	if (parse_loop(fd, vals) == 1)
		return (close(fd), vals->array = NULL, quit("Map error", vals), NULL);
	close(fd);
	fd = get_map(map);
	if (fd == -1)
		return (display_error("Map not found."), NULL);
	return (get_array(fd, vals, create_array(vals)));
}
