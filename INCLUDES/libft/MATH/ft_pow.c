/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:00:31 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/13 10:07:23 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

int	ft_pow(int n, int pow)
{
	if (pow < 0)
		return (0);
	if (pow > 0)
		return (n * ft_pow(n, pow - 1));
	return (1);
}

int	get_lower_bound(int x, int n)
{
	int	i;

	i = 1;
	while (ft_pow(n, i) < x)
		i++;
	if (i == 1)
		return (n);
	return (ft_pow(n, i - 1));
}

int	get_upper_bound(int x, int n)
{
	int	i;

	i = 1;
	while (ft_pow(n, i) < x)
		i++;
	return (ft_pow(n, i));
}
