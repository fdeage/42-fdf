/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 16:43:49 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/02 14:12:34 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void		exit_fdf(t_file *file, t_params *params)
{
	ft_putstr_color("TRY EXITING... ", COL_LIGHT_GREEN);
	free_file(file);
	close(file->fd);
	free(file);
	mlx_destroy_window(params->e->mlx, params->e->win);
	mlx_destroy_image(params->e->mlx, params->e->img->ptr);
	free(params->e->mlx);
	free(params->e);
	free(params);
	ft_putstr_color("SUCCESSFUL EXIT!\n", COL_GREEN);
	exit(EXIT_SUCCESS);
}

static void	key_choice(unsigned int key, t_params *params)
{
	if (key == KEY_PLUS)
	{
		params->x_zoom++;
		params->y_zoom++;
	}
	else if (key == KEY_MINUS)
	{
		params->x_zoom--;
		params->y_zoom--;
	}
	else if (key == KEY_PAGEUP)
		params->coeff_z += 0.05;
	else if (key == KEY_PAGEDOWN)
		params->coeff_z -= 0.05;
	else if (key == KEY_UP)
		params->y_shift -= 10;
	else if (key == KEY_DOWN)
		params->y_shift += 10;
	else if (key == KEY_LEFT)
		params->x_shift -= 10;
	else if (key == KEY_RIGHT)
		params->x_shift += 10;
}

int			key_press(unsigned int key, t_params *params)
{
	if (key == KEY_ESC)
		exit_fdf(params->file, params);
	else
	{
		key_choice(key, params);
		compute_projection(params, params->file);
		mlx_put_image_to_window(params->e->mlx, params->e->win,
			params->e->img->ptr, 0, 0);
	}
	return (0);
}

int			expose_hook(t_params *params)
{
	compute_projection(params, params->file);
	mlx_put_image_to_window(params->e->mlx, params->e->win,
		params->e->img->ptr, 0, 0);
	return (0);
}
