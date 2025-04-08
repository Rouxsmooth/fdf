/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:41:40 by m.zaian           #+#    #+#             */
/*   Updated: 2024/12/13 17:18:48 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n--)
	{
		if (*ptr == (unsigned char) c)
			return (s);
		ptr++;
		s++;
	}
	return (NULL);
}
/*
int	main(void)
{
	#include <stdio.h>
	char	str[] = "Hello, World!";
	char	*expected;
	char	*test;
	int		c;
	size_t	n;

	n = 5;
	c = 'o';
	expected = memchr(str, c, n);
	test = ft_memchr(str, c, n);
	printf("'%s' | '%s' : %s\n", expected ? expected : "(null)",
		test ? test : "(null)", expected == test ? "SUCCESS" : "FAIL");
	return (0);
}
*/