/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:04:24 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/24 16:11:21 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int	alloc_error(void)
{
	return (display_error("Allocation error"), -1);
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
		while (curr_line[i] && !(curr_line[i] == ' '))
			i--;
		i--;
	}
	return (item_count);
}

char	***create_array(t_vals *window)
{
	char	***array;
	int		i;

	array = (char ***) ft_calloc(window->y + 1, sizeof(char **));
	i = 0;
	while (i < window->y)
	{
		array[i] = (char **) ft_calloc(window->x + 1, sizeof(char **));
		i++;
	}
	return (array);
}
