/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:09:37 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/30 21:35:48 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "../.mlx/mlx.h"
# include <math.h>
#include "../../libft/INCLUDES/libft.h"

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
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_press
{
	int	w;
	int	a;
	int	s;
	int	d;
}	t_press;

typedef struct s_mlx
{
	int		screen_height;
	int		screen_width;
	void	*img;
	void	*mlxptr;
	void	*win;
}	t_mlx;

typedef struct s_map
{
	char	*title;
	float	base_map_ratio;
	float	map_ratio;
	float	max_map_ratio;
	float	min_map_ratio;
	int		array_height;
	int		array_width;
	int		has_color;
	int		highest_z;
	int		lowest_z;
}	t_map;

typedef struct s_vals
{
	char	***array;
	float	x_offset;
	float	y_offset;
	int		already_drew;
	t_map	map;
	t_mlx	mlx;
	t_point	point;
	t_press	pressing;
}	t_vals;

/* draw.c */
void			drawmap(t_vals *vals);
void			drawlow(t_vals *vals, t_point p1, t_point p2);
void			drawhigh(t_vals *vals, t_point p1, t_point p2);

/* draw_utils.c */
void			put_pixel(t_vals *vals);
t_point			setpoint(int x, int y, t_vals *vals);
t_point			addratio(t_point point, int ratio);
t_point			get_iso(t_point point, t_vals *vals);

/* hooks.c */
int				key_release(int keycode, t_vals *vals);
int				mouse_down(int mousecode, int mouse_x, int mouse_y,
					t_vals *vals);
void			hooks_loop(t_vals *vals);

/* hooks_event.c */
int				mlx_close(t_vals *vals);
int				move_world(t_vals *vals, t_press pressing);
int				reset_map(t_vals *vals);

/* init.c */
void			init_vals(t_vals *vals, char *title);

/* line_utils.c */
void			create_line(t_vals *vals, t_point p1, t_point p2);
int				interpolate_color(int color1, int color2, float div);
unsigned int	getcolor(char *hexinstr, t_vals *vals);
t_linecalc		set_low(t_point p1, t_point p2);
t_linecalc		set_high(t_point p1, t_point p2);

/* main.c */
void			mlx_del(t_vals *vals);
void			quit(char *error_msg, t_vals *vals);

/* parser_utils.c */
int				get_itemcount(char *curr_line);
int				get_map(char *map);
char			***create_array(t_vals *vals);
char			*set_title(char *map);
void			get_extremums(t_vals *vals);

/* parser.c */
char			***map_parser(char *map, t_vals *vals);

/* quit.c */
void			vals_del(t_vals *vals);
void			mlx_del(t_vals *vals);
void			quit(char *error_msg, t_vals *vals);

/* mlx keycode macro */
# define K_A 97
# define K_ESCAPE 65307
# define K_D 100
# define K_S 115
# define K_SPACE 32
# define K_W 119
# define M_SCROLLUP 4
# define M_SCROLLDOWN 5

#endif