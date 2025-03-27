/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:09:37 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/27 19:28:42 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "../.mlx/mlx.h"
# include <math.h>
#include "../../libft/INCLUDES/libft.h"
#include <stdio.h>

typedef struct s_interpolate
{
	float	step;
	float	div;
}	t_interpolate;

typedef struct s_linecalc
{
	int				dx;
	int				dy;
	int				err;
	int				inc;
	t_interpolate	interpolator;
}	t_linecalc;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_vals
{
	int		already_drew;
	char	***array;
	int		array_height;
	int		array_width;
	int		height;
	void	*img;
	int		map_ratio;
	void	*mlx;
	char	*title;
	int		width;
	void	*win;
	t_point	point;
}	t_vals;

/* draw.c */
void			drawmap(t_vals *vals);
void			drawlow(t_vals *vals, t_point p1, t_point p2);
void			drawhigh(t_vals *vals, t_point p1, t_point p2);

/* draw_utils.c */
void			put_pixel(t_vals *vals);
t_point			setpoint(int x, int y, char *z, char *color);
t_point			addratio(t_point point, int ratio);
t_point			get_iso(t_point point, t_vals *vals);

/* hooks.c */
void			hooks_loop(t_vals *vals);

/* hooks_event.c */
int				key_release(int keycode, t_vals *vals);
int				mlx_close(t_vals *vals);

/* init.c */
t_vals			init_vals(char *title);

/* line_utils.c */
void			create_line(t_vals *vals, t_point p1, t_point p2);
unsigned int	getcolor(char *hexinstr);
int				interpolate_color(int color1, int color2, float div);
t_linecalc		set_low(t_point p1, t_point p2);
t_linecalc		set_high(t_point p1, t_point p2);

/* main.c */
void			mlx_del(t_vals *vals);
void			quit(char *error_msg, t_vals *vals);

/* parser_utils.c */
int				alloc_error(void);
int				get_itemcount(char *curr_line);
char			*set_title(char *map);
int				get_map(char *map);
char			***create_array(t_vals *vals);

/* parser.c */
char			***map_parser(char *map, t_vals *vals);

/* quit.c */
void			vals_del(t_vals *vals);
void			mlx_del(t_vals *vals);
void			quit(char *error_msg, t_vals *vals);

/* mlx keycode macro */
# define K_ESCAPE 65307

#endif