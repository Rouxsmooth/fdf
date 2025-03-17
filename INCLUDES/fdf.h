/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:09:37 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/17 09:45:53 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "../.mlx/mlx.h"
#include "../../libft/INCLUDES/libft.h"
#include <stdio.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_vals
{
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;
	char	*title;
	char	***array;
	t_point	point;
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
int		key_release(int keycode, t_vals *vals);
int		mlx_close(t_vals *vals);

/* mlx keycode macros */

# define K_A 97
# define K_B 98
# define K_C 99
# define K_D 100
# define K_E 101
# define K_F 102
# define K_G 103
# define K_H 104
# define K_I 105
# define K_J 106
# define K_K 107
# define K_L 108
# define K_M 109
# define K_N 110
# define K_O 111
# define K_P 112
# define K_Q 113
# define K_R 114
# define K_S 115
# define K_T 116
# define K_U 117
# define K_V 118
# define K_W 119
# define K_X 120
# define K_Y 121
# define K_Z 122

# define K_SPACE 32
# define K_ESCAPE 65307

# define MOUSE_CLICK_L 1
# define MOUSE_CLICK_R 3
# define MOUSE_CLICK_M 2
# define MOUSE_SCROLL_U 4
# define MOUSE_SCROLL_D 5

#endif