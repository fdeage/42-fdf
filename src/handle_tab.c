/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 19:11:02 by fdeage            #+#    #+#             */
/*   Updated: 2015/04/16 11:02:44 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "fdf.h"

void	get_minmax(t_file *file, t_params *params)
{
	size_t	i;
	size_t	j;

	i = 0;
	params->min = INT_MAX + 1;
	params->max = INT_MAX;
	while (i < file->nb_line)
	{
		j = 0;
		while (j < file->nb_col)
		{
			if ((file->tab)[i][j] < params->min)
				params->min = (file->tab)[i][j];
			if ((file->tab)[i][j] > params->max)
				params->max = (file->tab)[i][j];
			j++;
		}
		i++;
	}
	params->step = (double)256 / (params->max - params->min);
}

void	free_file(t_file *file)
{
	size_t	i;
	t_list	*tmp;
	t_list	*next;

	i = 0;
	while (i < file->nb_line)
	{
		free((file->tab)[i]);
		++i;
	}
	free(file->tab);
	tmp = file->lines;
	while (tmp)
	{
		next = tmp->next;
		free(LINE->line);
		free(LINE->tab);
		free(LINE);
		tmp = next;
	}
}

int		build_tab(t_file *file)
{
	size_t	i;
	size_t	j;
	t_list	*tmp;

	if (!(file->tab = (int **)malloc(file->nb_line * sizeof(*(file->tab)))))
		return (-1);
	i = 0;
	tmp = file->lines;
	file->nb_col = LINE->len;
	while (i < file->nb_line && tmp)
	{
		if (!((file->tab)[i] = (int *)malloc(LINE->len * sizeof(int))))
			return (-1);
		j = 0;
		while (j < LINE->len)
		{
			(file->tab)[i][j] = LINE->tab[j];
			++j;
		}
		tmp = tmp->next;
		++i;
	}
	return (0);
}
