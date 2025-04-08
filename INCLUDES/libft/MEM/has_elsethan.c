/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_elsethan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 03:39:58 by mzaian            #+#    #+#             */
/*   Updated: 2025/02/01 03:40:11 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

int	has_elsethan(char *str, int (f)(int))
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!f(str[i]))
			return (1);
		i++;
	}
	return (0);
}
