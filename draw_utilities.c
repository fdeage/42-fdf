/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 21:29:05 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/30 18:45:18 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include </opt/X11/include/X11/X.h>
#include "fdf.h"

void	pixel_store(t_env *e, int x, int y, int color)
{
	int	pos;

	if ((x < (int)e->width && y < (int)e->height) && (x >= 0 && y >= 0))
	{
		pos = y * e->img->size_line + x * (e->img->bpp / 8);
		e->img->data[pos] = mlx_get_color_value(e->mlx, color);
		e->img->data[pos + 1] = mlx_get_color_value(e->mlx, color >> 8);
		e->img->data[pos + 2] = mlx_get_color_value(e->mlx, color >> 16);
	}
}

void	clear_image(t_env *e)
{
	register size_t	i;
	register size_t	j;

	i = 0;
	while (i < e->width)
	{
		j = 0;
		while (j < e->height)
		{
			pixel_store(e, i, j, COLOR_BLACK);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img->ptr, 0, 0);
}

void	draw_pixel_around(t_params *params, t_point *p, int col)
{
	register int	i;
	register int	j;

	i = p->x - DOT_SIZE;
	while (i < p->x + DOT_SIZE)
	{
		j = p->y - DOT_SIZE;
		while (j < p->y + DOT_SIZE)
		{
			pixel_store(params->e, i, j, col);
			++j;
		}
		++i;
	}
}

void	draw_line(t_params *params, t_point a, t_point b, int col)
{
	t_line_tools	t;

	t.dx = ABS(b.x - a.x);
	t.sx = (a.x < b.x ? 1 : -1);
	t.dy = ABS(b.y - a.y);
	t.sy = (a.y < b.y ? 1 : -1);
	t.err1 = (t.dx > t.dy ? t.dx : -t.dy) / 2;
	col = 255 * (params->step * (((a.k + b.k) / 2) - params->min)) + 16711935;
	while (!(a.x == b.x && a.y == b.y))
	{
		pixel_store(params->e, a.x, a.y, col);
		t.err2 = t.err1;
		if (t.err2 > -t.dx)
		{
			t.err1 -= t.dy;
			a.x += t.sx;
		}
		if (t.err2 < t.dy)
		{
			t.err1 += t.dx;
			a.y += t.sy;
		}
	}
}
