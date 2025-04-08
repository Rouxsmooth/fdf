/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 03:36:24 by m.zaian           #+#    #+#             */
/*   Updated: 2024/12/13 16:50:05 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	if (!s[0] || !s)
		return (ft_calloc(1, sizeof(char)));
	dup = (char *) ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
/*
int	main(void)
{
	#include <stdio.h>
	printf("%s\n", ft_strdup("sadfvbf"));
}*/