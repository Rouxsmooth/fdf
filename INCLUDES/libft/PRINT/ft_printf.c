/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:51:45 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/23 19:10:57 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

int	check_cases(const char *s, int *index, va_list args, char *mods)
{
	if (s[*index] == 'X')
		return (ft_put_x(va_arg(args, unsigned int), "0123456789ABCDEF", mods));
	else if (s[*index] == 'x')
		return (ft_put_x(va_arg(args, unsigned int), "0123456789abcdef", mods));
	else if (s[*index] == 'd' || s[*index] == 'i')
		return (ft_put_di(va_arg(args, int), mods));
	else if (s[*index] == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	else if (s[*index] == 'l' && (s[*index + 1] == 'd' || s[*index + 1] == 'i'))
		return ((*index)++, ft_put_ldli(va_arg(args, long), mods));
	else if (s[*index] == '%')
		return (write(1, &s[*index], 1), 1);
	else if (s[*index] == 's')
		return (ft_put_s(va_arg(args, char *), mods));
	else if (s[*index] == 'u')
		return (ft_put_u(va_arg(args, int)));
	else if (s[*index] == 'p')
		return (ft_put_p(va_arg(args, void *), "0123456789abcdef", mods));
	else if (!s[*index])
		return (-1);
	else if (ft_isascii(s[*index]))
		return (ft_put_ascii(s[*index], mods, s));
	else
		return (0);
}

char	*has_modifiers(const char *str, int i)
{
	int		j;
	char	*modifiers;

	j = i;
	while (str[j] == '#' || str[j] == ' ' || str[j] == '+'
		|| ft_isdigit(str[j]))
		j++;
	modifiers = (char *) ft_calloc(j - i + 1, sizeof(char));
	if (!modifiers)
		return (NULL);
	j = 0;
	while (str[i] == '#' || str[i] == ' ' || str[i] == '+'
		|| ft_isdigit(str[i]))
		modifiers[j++] = str[i++];
	return (modifiers);
}

int	handle_flags(const char *str, va_list args, int *i)
{
	char	*mods;
	int		len;

	(*i)++;
	mods = has_modifiers(str, *i);
	if (mods && *mods)
		(*i) += ft_strlen(mods);
	len = check_cases(str, i, args, mods);
	return (ft_del(mods), len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	int		prevlen;
	va_list	args;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		prevlen = len;
		if (str[i] == '%')
			len += handle_flags(str, args, &i);
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		if (prevlen > len)
			return (-1);
		i++;
	}
	return (va_end(args), len);
}
