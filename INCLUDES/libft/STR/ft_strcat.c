/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:12:47 by mzaian            #+#    #+#             */
/*   Updated: 2024/12/18 14:12:57 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

size_t	ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = destlen;
	j = 0;
	while (j < srclen)
		dest[i++] = src[j++];
	return (destlen + srclen);
}
