/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:00:25 by m.zaian           #+#    #+#             */
/*   Updated: 2025/01/23 18:33:19 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (start > ft_strlen(s) || !*s || !s)
		return ((char *) ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	sub = (char *) ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = 0;
	return (sub);
}

/*
int	main(void)
{
	#include <stdio.h>
	printf("%s\n", ft_substr("0123456789", 9, 10));
}*/