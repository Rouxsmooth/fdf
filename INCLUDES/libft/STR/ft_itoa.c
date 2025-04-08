/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 01:14:44 by m.zaian           #+#    #+#             */
/*   Updated: 2024/12/13 16:49:06 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

static int	ft_get_numlen(long nbr)
{
	int	numlen;

	numlen = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		numlen++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		numlen++;
	}
	return (numlen);
}

static char	*ft_rec_calc(long nbr, char *converted, int index)
{
	if (nbr >= 10)
		ft_rec_calc(nbr / 10, converted, index - 1);
	converted[index] = nbr % 10 + 48;
	return (converted);
}

char	*ft_itoa(int n)
{
	char	*converted;
	long	nbr;
	int		numlen;

	nbr = n;
	numlen = ft_get_numlen(nbr);
	converted = (char *) ft_calloc(numlen + 1, sizeof(char));
	if (converted == NULL)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		converted[0] = 45;
		ft_rec_calc(nbr, converted, numlen - 1);
	}
	else
		ft_rec_calc(nbr, converted, numlen - 1);
	converted[numlen] = 0;
	return (converted);
}

/*int	main(void)
{
	#include <stdio.h>
	printf("-1 | %s\n", ft_itoa(-1));
}  */