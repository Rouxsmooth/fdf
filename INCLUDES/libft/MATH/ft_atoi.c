/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:01:13 by m.zaian           #+#    #+#             */
/*   Updated: 2025/03/31 16:04:09 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nbr;

	sign = 1;
	i = 0;
	nbr = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr *= 10;
		nbr += (nptr[i] - 48);
		i++;
	}
	return (nbr * sign);
}

long int	ft_atol(const char *nptr)
{
	int			i;
	int			sign;
	long int	nbr;

	sign = 1;
	i = 0;
	nbr = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr *= 10;
		nbr += (nptr[i] - 48);
		i++;
	}
	return (nbr * sign);
}
