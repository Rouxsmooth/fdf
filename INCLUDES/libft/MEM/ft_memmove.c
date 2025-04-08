/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:42:02 by mzaian            #+#    #+#             */
/*   Updated: 2024/12/13 17:18:55 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	if (dest > src)
	{
		i = n;
		while (i != 0)
		{
			i--;
			((char *) dest)[i] = ((char *) src)[i];
		}
	}
	else
		dest = ft_memcpy(dest, src, n);
	return (dest);
}
