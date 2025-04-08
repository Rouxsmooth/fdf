/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:26:06 by m.zaian           #+#    #+#             */
/*   Updated: 2024/12/13 17:18:58 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *) s;
	while (n--)
		*ptr++ = c;
	return (s);
}

/*int main(void)
{
	#include <stdio.h>
	char test1[20] = "Hello, world!";
	char test2[20] = "Hello, world!";
	char expected1[20];
	int result1;
	int result2;
	
	memset(expected1, 50, 5);
	ft_memset(test1, 50, 5);
	ft_memset(test2, '\0', 5);
	expected1[5] = '\0';
	result1 = (strncmp(test1, expected1, 5) == 0) ? 1 : 0;
	result2 = (test2[0] == '\0' && test2[1] == '\0' && test2[2] == '\0' &&
				   test2[3] == '\0' && test2[4] == '\0') ? 1 : 0;
	printf("Test 1: %s\n", result1 ? "SUCCESS" : "FAIL");
	printf("Test 2 (null fill): %s\n", result2 ? "SUCCESS" : "FAIL");
	return 0;
}*/
