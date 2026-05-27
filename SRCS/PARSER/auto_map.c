/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 06:43:14 by mzaian            #+#    #+#             */
/*   Updated: 2026/05/22 12:53:22 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../INCLUDES/fdf.h"

int	get_mapcount()
{
	int				mapcount;
	char			*path;
	DIR				*dir;
	struct dirent	*entry;

	path = ".maps/";
	dir = opendir(path);
	if (!dir)
		return (-1);
	entry = readdir(dir);
	mapcount = 2;
	while (entry->d_name[mapcount])
		mapcount++;
	printf("mapcount : %d\n", mapcount - 2);
	pause();
	return (mapcount - 2);
}

long int	get_utime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_usec);
}

long int	get_ran()
{
	long int	time;

	time = get_utime();
	time = time * 69 + (6 * ft_sqrt(69) + 9);
	return (time % get_mapcount());
}

char	*get_ran_map()
{
	char			*path;
	struct stat		st;
	long int		n;
	DIR				*dir;
	struct dirent	*entry;

	path = ".maps/";
	dir = opendir(path);
	if (!dir)
	return (NULL);
	n = get_ran();
	entry = readdir(dir);
	while (entry)
	
		if (stat(path))
		
	}
	return ()
}

int start_auto_choosing()
{
	int			map_count;
	int			fd;

	map = (get_ran_map());
	fd = open(map, O_RDONLY);
	if (fd)
	return (time % map_count);
}

int auto_map(char *map)
{
	if (!ft_strncmp(map, "auto", ft_max(ft_strlen(map), 4)))
		return (start_auto_choosing());
	if (!ft_strncmp(map, "random", ft_max(ft_strlen(map), 4)))
		return (start_auto_choosing());
	if (!ft_strncmp(map, "ran", ft_max(ft_strlen(map), 4)))
		return (start_auto_choosing());
	return (NULL);
}