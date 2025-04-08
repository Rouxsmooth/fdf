/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:56:46 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/17 01:10:51 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

//has to be alloc'd by `malloc()` or else because of `ft_del()`
size_t	ft_insert_str(char **dest, char *src, int index)
{
	char	*end;
	char	*newdest;
	size_t	destlen;
	size_t	srclen;
	size_t	newdestlen;

	destlen = ft_strlen(*dest);
	if (!*dest || !src || (size_t) index > destlen)
		return (-1);
	srclen = ft_strlen(src);
	end = ft_substr(*dest, index, destlen - index);
	newdest = ft_calloc(destlen + srclen + 1, sizeof(char));
	ft_strlcpy(newdest, *dest, index + 1);
	if (!end || !newdest)
		return (-1);
	ft_strcat(newdest, src);
	newdestlen = ft_strcat(newdest, end);
	ft_del(*dest);
	*dest = newdest;
	return (ft_del(end), newdestlen);
}
