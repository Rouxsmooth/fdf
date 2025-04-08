/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:22:53 by m.zaian           #+#    #+#             */
/*   Updated: 2024/12/13 16:50:26 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	end;
	size_t	start;
	char	*trimmed;

	end = 0;
	if (!s1[0])
		return (trimmed = ft_strdup(s1));
	while (ft_strchr(set, s1[end]) && s1[end])
		end++;
	start = end;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]) && s1[end])
		end--;
	trimmed = ft_substr(s1, start, end - start + 1);
	return (trimmed);
}
/*
int	main(void)
{
	char *str = "";
	printf("'%s'\n", ft_strtrim(str, " x"));
}*/