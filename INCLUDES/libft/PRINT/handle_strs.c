/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_strs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 07:28:11 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/23 19:11:12 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

int	ft_put_s(char *str, char *modifiers)
{
	int	format;
	int	len;
	int	i;
	int	fulllen;

	if (!str)
		return (write(1, &"(null)", 6), 6);
	len = ft_strlen(str);
	if (modifiers && *modifiers)
	{
		i = 0;
		while (!ft_isdigit(modifiers[i]) && modifiers[i])
			i++;
		format = ft_abs(ft_atoi(&modifiers[i]));
		if (format <= len)
			return (write(1, &str[0], len), len);
		fulllen = format;
		while (format > len)
		{
			write(1, &" ", 1);
			format--;
		}
		return (write(1, &str[0], len), fulllen);
	}
	return (write(1, &str[0], len), len);
}

int	handle_spaceplus(char *modifiers, long long n)
{
	int	len;

	len = 0;
	if (modifiers && ft_strchr(modifiers, '+') && n >= 0)
	{
		write(1, &"+", 1);
		len++;
	}
	else if (modifiers && ft_strchr(modifiers, ' ') && n >= 0)
	{
		write(1, &" ", 1);
		len ++;
	}
	return (len);
}

static int	get_hex_len(unsigned long nb)
{
	int	len;

	len = 1;
	while (nb >= 16)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_put_x(unsigned long nbr, char *base, char *modifiers)
{
	char	*hex;
	int		len;
	int		i;

	len = get_hex_len(nbr);
	if (modifiers && ft_strchr(modifiers, '#') && nbr)
		len += 2;
	i = len;
	hex = (char *) ft_calloc(len, sizeof(char));
	if (!nbr)
		hex[--i] = '0';
	while (nbr > 0)
	{
		hex[--i] = base[nbr % 16];
		nbr /= 16;
	}
	if (modifiers && ft_strchr(modifiers, '#') && i > 1)
	{
		if (base[15] == 'F')
			hex[--i] = 'X';
		else
			hex[--i] = 'x';
		hex[--i] = '0';
	}
	return ((write(1, &hex[i], len - i), ft_del(hex)), len - i);
}

int	ft_put_p(void *ptr, char *base, char *modifiers)
{
	char			*hex;
	int				len;
	int				i;
	unsigned long	nbr;

	if (!ptr)
		return (write(1, &"(nil)", 5), 5);
	nbr = (unsigned long) ptr;
	len = 2 + get_hex_len(nbr);
	len += handle_spaceplus(modifiers, 0);
	i = len - 3;
	hex = (char *) ft_calloc(len - 2, sizeof(char));
	while (i >= 0)
	{
		hex[i] = base[nbr % 16];
		nbr /= 16;
		i--;
	}
	write(1, &"0x", 2);
	return ((write(1, &hex[0], len - 2), ft_del(hex)), len);
}
