/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:10:45 by m.zaian           #+#    #+#             */
/*   Updated: 2025/01/23 18:33:35 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	int		i;
	int		j;

	join = (char *) ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (join == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	return (join);
}

char	*ft_strnjoin(char *s1, const char *s2, int n)
{
	char	*join;
	int		i;
	int		j;

	if (n == -1)
		n = ft_strlen(s2);
	if (!n)
		return (NULL);
	join = (char *) ft_calloc(ft_strlen(s1) + n + 1, sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	if (s1)
		ft_del(s1);
	j = 0;
	while (s2 && s2[j] && j < n)
		join[i++] = s2[j++];
	return (join);
}
/*
int	main(void)
{
	#include <stdio.h>
	char * s = ft_strjoin("tripouille", "42");
	printf("%s\n", s);
}*/