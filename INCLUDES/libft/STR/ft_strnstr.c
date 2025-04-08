/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:35:00 by m.zaian           #+#    #+#             */
/*   Updated: 2024/12/13 16:50:20 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[i])
		return ((char *) big);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && little[j] && big[i + j]
			&& i + j < len)
			j++;
		if (!little[j])
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	#include <stdio.h>
	printf("is siffler | %s ; %s\n",
		ft_strnstr("Je ne sais siffler", "iffler", 1),
		ft_strcmp(ft_strnstr("Je ne sais siffler", "iffler", 1),
		"is siffler") == 0 ? "SUCCESS" :  "FAIL");
	printf("iffler | %s ; %s\n",
		ft_strnstr("Je ne sais siffler", "iffler", 2),
		ft_strcmp(ft_strnstr("Je ne sais siffler","iffler", 2),
		"iffler") == 0 ? "SUCCESS" :  "FAIL");	
}*/