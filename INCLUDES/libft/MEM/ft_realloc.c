/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:04:30 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/13 10:06:01 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*reallocd;

	if (!ptr)
		return ((void *) malloc(size));
	if (!size)
		return (free(ptr), NULL);
	reallocd = malloc(size);
	ft_memcpy(reallocd, ptr, size);
	return (free(ptr), reallocd);
}
