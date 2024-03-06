/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:04:30 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/10 12:42:01 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include </opt/X11/include/X11/X.h>
#include <stdlib.h>
#include <fcntl.h>
#include "fdf.h"
#include "libft.h"

static int		check_files(int ac, char **av)
{
	int		fd;

	if (ac < 2)
		fdf_errors("No file entered.\n");
	else if (ac > 2)
		fdf_errors("Too many files entered.\n");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		fdf_errors("Failed to open the file.\n");
	return (fd);
}

static t_env	*init_read(t_file *file, t_env *e)
{
	if (read_tab(file) == -1)
		return (NULL);
	if (build_tab(file) == -1)
		return (NULL);
	e->width = WIDTH;
	e->height = HEIGHT;
	if (!(e->mlx = mlx_init()))
		exit(EXIT_FAILURE);
	if (!(e->win = mlx_new_window(e->mlx, e->width, e->height, "new")))
		exit(EXIT_FAILURE);
	mlx_do_key_autorepeaton(e->mlx);
	if (!(e->img = (t_img *)ft_memalloc(sizeof(t_img))))
		return (NULL);
	e->img->ptr = mlx_new_image(e->mlx, e->width, e->height);
	e->img->data = mlx_get_data_addr(e->img->ptr, &(e->img->bpp),
		&(e->img->size_line), &(e->img->endian));
	return (e);
}

static void		init_params(t_params *params, t_env *e, int **tab)
{
	params->tab = tab;
	params->e = e;
	params->coeff_z = -0.25;
	params->x_zoom = 25;
	params->y_zoom = 20;
	params->x_shift = 700;
	params->y_shift = 400;
	params->time = 0;
	params->nb_print = 0;
	params->reprint = 1;
}

int				main(int ac, char **av)
{
	t_file		*file;
	t_env		*e;
	t_params	*params;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		return (EXIT_FAILURE);
	if ((file->fd = check_files(ac, av)) == -1)
		return (EXIT_FAILURE);
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (EXIT_FAILURE);
	if (!(e = init_read(file, e)))
		return (EXIT_FAILURE);
	if (!(params = (t_params *)malloc(sizeof(t_params))))
		return (EXIT_FAILURE);
	init_params(params, e, file->tab);
	get_minmax(file, params);
	params->file = file;
	mlx_expose_hook(e->win, &print_file, params);
	mlx_hook(e->win, KeyPress, KeyPressMask, &key_press, params);
	mlx_loop_hook(e->mlx, &loop_hook, params);
	mlx_loop(e->mlx);
	return (EXIT_SUCCESS);
}
