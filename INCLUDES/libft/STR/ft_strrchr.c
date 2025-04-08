/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:45:37 by m.zaian           #+#    #+#             */
/*   Updated: 2024/12/13 16:50:23 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i != 0 && s[i] != (unsigned char) c)
		i--;
	if (i == 0 && s[0] != (unsigned char) c)
		return ((char *) NULL);
	else
		return ((char *) &s[i]);
}
/*

int	main(void)
{
	#include <stdio.h>
	char	*str = "s jlnofrjnpvjerpvjnrepjnv";
	char	*test1 = ft_strrchr(str, 's');
	char	*test2 = strrchr(str, 's');
	if (test1 == NULL)
		printf("test1 : (NULL)\n");
	if (test2 == NULL)
		printf("test2 : (NULL)\n");
	//else
	//	printf("%s\n", test2);
	if (test1 != NULL && test2 != NULL)
	{
		printf("%s | %s ; %s\n", test1, test2,
			ft_strcmp(test1, test2) == 0 ? "SUCCESS" : "FAIL");
	}
}*/