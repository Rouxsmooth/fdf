/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:09:37 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/24 16:22:18 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "../.mlx/mlx.h"
#include "../../libft/INCLUDES/libft.h"

typedef struct s_vals
{
	int		x;
	int		y;
	void	*mlx;
	char	*title;
	void	*mlx_window;
	void	*img;
	char	***array;
	//image & window
}	t_vals;

/* parser.c */
char	***map_parser(char *map, t_vals *window);

/* parser_utils.c */
int		alloc_error(void);
int		get_itemcount(char *curr_line);
char	***create_array(t_vals *window);



//cc SRCS/main.c -L .mlx -l:libmlx.a -L ../libft -l:libft.a -lX11 -lXext
#endif