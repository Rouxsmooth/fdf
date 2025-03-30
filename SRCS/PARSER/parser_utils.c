/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:04:24 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/30 22:03:09 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

void	get_extremums(t_vals *vals)
{
	int	i;
	int	j;
	int	curr_nbr;

	i = 0;
	vals->map.lowest_z = 0;
	vals->map.highest_z = 0;
	while (i < vals->map.array_height)
	{
		j = 0;
		while (j < vals->map.array_width)
		{
			curr_nbr = ft_atoi(vals->array[i][j]);
			if (i == 0 && j == 0)
				vals->map.lowest_z = curr_nbr;
			if (curr_nbr < vals->map.lowest_z)
				vals->map.lowest_z = curr_nbr;
			if (curr_nbr > vals->map.highest_z)
				vals->map.highest_z = curr_nbr;
			j++;
		}
		i++;
	}
	return ;
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
	char	*temp;

	mappath = ft_strjoin(".maps/", map);
	if (!mappath)
		return (display_error("Allocation error"), -2);
	fd = open(mappath, O_RDONLY);
	if (fd != -1)
		return (ft_del(mappath), fd);
	temp = ft_strjoin(mappath, ".fdf");
	ft_del(mappath);
	fd = open(temp, O_RDONLY);
	ft_del(temp);
	if (fd != -1)
		return (fd);
	fd = open(map, O_RDONLY);
	return (fd);
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
		while (i > -1 && curr_line[i] != ' ')
			i--;
		i--;
	}
	return (item_count);
}

char	***create_array(t_vals *vals)
{
	char	***array;
	int		i;

	array = (char ***) ft_calloc(vals->map.array_height + 1, sizeof(char **));
	i = 0;
	while (i < vals->map.array_height)
	{
		array[i] = (char **) ft_calloc(vals->map.array_width + 1,
				sizeof(char *));
		if (!array[i])
			quit("Allocation error", vals);
		i++;
	}
	return (array);
}
