/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 06:43:14 by mzaian            #+#    #+#             */
/*   Updated: 2026/04/04 07:56:36 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *auto_map(char *map)
{
	if (!ft_strncmp(map, "auto", ft_max(ft_strlen(map), 4)))
		return (start_auto_choosing());
	if (!ft_strncmp(map, "random", ft_max(ft_strlen(map), 4)))
		return (start_auto_choosing());
	if (!ft_strncmp(map, "ran", ft_max(ft_strlen(map), 4)))
		return (start_auto_choosing());
	return (NULL);
}

int start_auto_choosing()
{
	long int	time;

	time = get_utime();
	
}