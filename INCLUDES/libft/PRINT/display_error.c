/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:51:29 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/17 18:41:11 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

int	display_error(char *output)
{
	return ((start_colored_output(2, 31), ft_putstr_fd("Error: ", 2),
			ft_putstr_fd(output, 2), close_colored_output(2)),
		write(1, "\n", 1));
}
