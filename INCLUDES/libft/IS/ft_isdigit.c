/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:58:44 by m.zaian           #+#    #+#             */
/*   Updated: 2025/01/23 14:11:52 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

int	has_digits(char *str)
{
	while (*str && !ft_isdigit(*str))
		str++;
	return (ft_isdigit(*str));
}
