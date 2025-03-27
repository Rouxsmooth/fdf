/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:35:22 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/27 18:59:01 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/fdf.h"

int	main(int argc, char **argv)
{
	t_vals	vals;

	if (argc != 2)
		return (display_error(ft_ternary("Map missing!", "Too much parameters",
					argc < 2)));
	vals = init_vals(argv[1]);
	hooks_loop(&vals);
	return (0);
}
