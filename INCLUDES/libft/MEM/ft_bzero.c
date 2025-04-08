/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:50:48 by m.zaian           #+#    #+#             */
/*   Updated: 2024/12/13 17:18:35 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *) s;
	while (n--)
		*ptr++ = 0;
}

/*
int main(void)
{
	#include <stdio.h>
	char	str1[] = "Hello, World!";
	char	str2[] = "Hello, World!";
	size_t	n = 4;
	size_t	i = 0;
	size_t	len = ft_strlen(str1);

	bzero(str1, n);
	ft_bzero(str2, n);

	while (i < len)
	{
		printf("%d | %d : %s\n", str1[i], str2[i],
			str1[i] == str2[i] ? "SUCCESS" : "FAIL");
		i++;
	}

	return 0;
}
*/