/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:14:10 by m.zaian           #+#    #+#             */
/*   Updated: 2025/03/21 10:07:13 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char) c)
		i++;
	if (s[i] == (unsigned char) c)
		return ((char *) &s[i]);
	return (NULL);
}

int	ft_strchrindex(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char) c)
		i++;
	if (s[i] == (unsigned char) c)
		return (i);
	return (-1);
}

/*
int	main(void)
{
	#include <stdio.h>
	char	*str = "test string for the glory of skibidi";
	char	*test1 = ft_strchr(str, 's');
	char	*test2 = strchr(str, 's');
	if (test1 == NULL)
		printf("test1 : (NULL)\n");
	if (test2 == NULL)
		printf("test2 : (NULL)\n");
	//else
	//	printf("%s\n", test2);
	else
	{
		printf("%s | %s ; %s\n", test1, test2,
			ft_strcmp(test1, test2) == 0 ? "SUCCESS" : "FAIL");
	}
}*/