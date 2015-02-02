/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 16:42:18 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/30 18:39:53 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

#define INV_SQRT_6			(0.4082483)
#define SQRT_3				(1.7320508)
#define _INV6_SQRT_3		(-0.7071067)

static void	isometric_conversion(t_point *p, t_params *display)
{
	double	trsf[2];

	trsf[0] = _INV6_SQRT_3 * (int)(p->i - p->j);
	trsf[1] = INV_SQRT_6 * (p->i + 2 * p->j + (display->coeff_z * p->k));
	p->x = (int)(display->x_zoom * trsf[0] + display->x_shift);
	p->y = (int)(display->y_zoom * trsf[1] + display->y_shift);
}

static void	compute_vlines(t_params *params, t_point p1)
{
	t_point	p2;

	p2.i = p1.i + 1;
	p2.j = p1.j;
	p2.k = params->tab[p2.i][p2.j];
	isometric_conversion(&p2, params);
	draw_line(params, p1, p2, COLOR_VLINE);
}

static void	compute_hlines(t_params *params, t_point p1)
{
	t_point	p3;

	p3.i = p1.i;
	p3.j = p1.j + 1;
	p3.k = params->tab[p3.i][p3.j];
	isometric_conversion(&p3, params);
	draw_line(params, p1, p3, COLOR_HLINE);
}

void		compute_projection(t_params *params, t_file *file)
{
	t_point		p1;

	clear_image(params->e);
	p1.i = 0;
	while (p1.i < file->nb_line - 0)
	{
		p1.j = 0;
		while (p1.j < file->nb_col - 0)
		{
			p1.k = (params->tab)[p1.i][p1.j];
			isometric_conversion(&p1, params);
			if (DISPLAY_POINTS)
				draw_pixel_around(params, &p1, COLOR_DOTS);
			if (p1.i < file->nb_line - 1)
				compute_vlines(params, p1);
			if (p1.j < file->nb_col - 1)
				compute_hlines(params, p1);
			++(p1.j);
		}
		++(p1.i);
	}
}
