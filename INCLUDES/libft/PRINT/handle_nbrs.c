/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nbrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 07:19:14 by mzaian            #+#    #+#             */
/*   Updated: 2024/12/17 15:43:30 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

int	ft_put_di(long n, char *modifiers)
{
	long	unit;
	int		len;

	len = handle_spaceplus(modifiers, n);
	if (n < 0)
	{
		write(1, &"-", 1);
		n *= -1;
		len++;
	}
	if (n > 9)
		len += ft_put_di(n / 10, NULL);
	unit = n % 10 + 48;
	return (write(1, &unit, 1), len + 1);
}

int	ft_put_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_put_u(n / 10);
	n = n % 10 + 48;
	len++;
	return (write(1, &n, 1), len);
}

int	ft_put_ldli(long long n, char *modifiers)
{
	long long	unit;
	int			len;

	if (n == (long long) 1 << 63)
		return (write(1, "-9223372036854775808LL", 21), 21);
	len = handle_spaceplus(modifiers, n);
	if (n < 0)
	{
		write(1, &"-", 1);
		n *= -1;
		len++;
	}
	if (n > 9)
		len += ft_put_di(n / 10, NULL);
	unit = n % 10 + 48;
	return (write(1, &unit, 1), len + 1);
}

int	ft_put_ascii(int c, char *mods, const char *s)
{
	int	len;
	int	i;

	len = 2;
	write(1, &"%", 1);
	if (ft_strchr(mods, '#'))
	{
		write(1, &"#", 1);
		len++;
	}
	if (ft_strchr(mods, '+'))
	{
		i = 0;
		while (s[i] && !ft_isalpha(s[i]))
			i++;
		if (ft_isalpha(s[i]))
			write(1, &"+", 1);
		len++;
	}
	else if (ft_strchr(mods, ' '))
		len++;
	if (ft_strchr(mods, ' ') && !ft_strchr(mods, '+') && ft_isalpha(c))
		write(1, &" ", 1);
	return (write(1, &c, 1), len);
}
