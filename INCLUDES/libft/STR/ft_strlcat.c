/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:36:42 by m.zaian           #+#    #+#             */
/*   Updated: 2024/12/18 14:13:45 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = dstlen;
	j = 0;
	if (dstlen < size - 1 && size != 0)
	{
		while (src[j] && dstlen + j < size - 1)
			dst[i++] = src[j++];
	}
	dst[i] = 0;
	if (dstlen > size)
		return (size + srclen);
	return (dstlen + srclen);
}

/*int	main(void)
{
	#include <stdio.h>
	char	dst[20] = "This is";
	char	*src = " a string!";
	size_t size = ft_strlcat(dst, src, 1);
	printf("%ld : \'%s\'\n", size, dst);
}*/