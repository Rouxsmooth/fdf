/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:09:37 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/26 18:47:21 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "../.mlx/mlx.h"
#include "../../libft/INCLUDES/libft.h"
#include <stdio.h>

typedef struct s_vals
{
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;
	char	***array;
	//image & window
}	t_vals;

/* parser.c */
char	***map_parser(char *map, t_vals *vals);

/* parser_utils.c */
int		alloc_error(void);
int		get_itemcount(char *curr_line);
char	*set_title(char *map);
int		get_map(char *map);
char	***create_array(t_vals *vals);

/* main.c */
void	mlx_del(t_vals *vals);
void	quit(char *error_msg, t_vals *vals);

/* hooks.c */
void	hooks_loop(t_vals *vals);

/* hooks_event.c */
int		mlx_close(t_vals *vals);

//cc SRCS/main.c -L .mlx -l:libmlx.a -L ../libft -l:libft.a -lX11 -lXext
#endif