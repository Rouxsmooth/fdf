/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:31:54 by m.zaian           #+#    #+#             */
/*   Updated: 2024/12/13 17:12:41 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	unit;

	if (n == -2147483648)
	{
		write(fd, &"-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, &"-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	unit = n % 10 + 48;
	write(fd, &unit, 1);
	return ;
}
/*
int main(void)
{
	ft_putnbr_fd(-2147483648 , 1);
	ft_putnbr_fd(2147483648 , 0);
	ft_putnbr_fd(2147483647 , 2);
}*/