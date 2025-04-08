/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:27:34 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/31 12:44:45 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

int	ft_min(int i1, int i2)
{
	if (i1 < i2)
		return (i1);
	return (i2);
}

int	ft_max(int i1, int i2)
{
	if (i1 > i2)
		return (i1);
	return (i2);
}

float	ft_floatmin(float i1, float i2)
{
	if (i1 < i2)
		return (i1);
	return (i2);
}

float	ft_floatmax(float i1, float i2)
{
	if (i1 > i2)
		return (i1);
	return (i2);
}
