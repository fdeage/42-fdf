/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 22:45:32 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/10 12:46:47 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "libft.h"

# define KEY_ESC		65307
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_PLUS		65451
# define KEY_MINUS		65453
# define KEY_PAGEUP		65365
# define KEY_PAGEDOWN	65366

# define WIDTH			1600
# define HEIGHT			1200

# define COLOR_BLACK	0x000000
# define COLOR_DOTS		0xB2BFED
# define COLOR_VLINE	0x7090E0
# define COLOR_HLINE	0x4070E6

# define DRAW_FACES		1

# define DOT_SIZE		0

# define BPP			24

# define LINE			((t_line *)(tmp->content))

# define DISPLAY_POINTS	1

# define IS_DIGIT(c)	((c) >= '0' && (c) <= '9')
# define ABS(c)			((c) < 0 ? -(c) : (c))
# define MIN(a, b)		((a) < (b) ? (a) : (b))
# define MAX(a, b)		((a) > (b) ? (a) : (b))

typedef struct			s_line
{
	int					nb;
	char				*line;
	int					*tab;
	size_t				len;
}						t_line;

typedef struct			s_file
{
	int					**tab;
	t_list				*lines;
	size_t				nb_line;
	size_t				nb_col;
	int					fd;
	int					ret;
}						t_file;

typedef struct			s_img
{
	void				*ptr;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_img				*img;
	size_t				width;
	size_t				height;
}						t_env;

typedef struct			s_point
{
	int					x;
	int					y;
	size_t				i;
	size_t				j;
	int					k;
}						t_point;

typedef struct			s_params
{
	t_file				*file;
	float				coeff_z;
	int					x_zoom;
	int					y_zoom;
	int					x_shift;
	int					y_shift;
	int					min;
	int					max;
	float				step;
	char				reprint;
	int					time;
	size_t				nb_print;
	int					**tab;
	t_env				*e;
}						t_params;

typedef struct			s_line_tools
{
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					err1;
	int					err2;
}						t_line_tools;

/*
** errors.c - OK
*/

int						add_line(t_file *file, char *str, int i);
void					check_line(const char *str, size_t line);
void					fdf_errors(const char *str);

/*
** key_handling.c - OK
*/

void					exit_fdf(t_file *file, t_params *par);
int						key_press(unsigned int key, t_params *par);
int						print_file(t_params *par);
int						loop_hook(t_params *params);

/*
** read.c - OK
*/

int						read_tab(t_file *file);

/*
** tabs.c - OK
*/

int						build_tab(t_file *file);
void					print_file_tab(t_file *file);
void					free_file(t_file *file);
void					get_minmax(t_file *file, t_params *par);

/*
** compute.c
*/

void					compute_projection(t_params *par, t_file *file);

/*
** draw.c
*/

void					clear_image(t_env *e);
void					pixel_store(t_env *e, int x, int y, int color);
void					draw_pixel_around(t_params *par, t_point *p, int col);
void					draw_line(t_params *par, t_point a, t_point b, int col);

#endif
