/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:22:19 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/05 12:10:58 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

void	fdf_errors(const char *str)
{
	ft_putstr_color(str, COL_RED);
	exit(EXIT_FAILURE);
}

void	check_line(const char *str, size_t line)
{
	register size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && !ft_isdigit(str[i]) && !ft_isspace(str[i]))
		{
			ft_putstr_color("Bad character: ", COL_RED);
			ft_putchar('\"');
			ft_putchar(str[i]);
			ft_putchar('\"');
			ft_putstr_color(" at line ", COL_LIGHT_RED);
			ft_putnbr(line + 1);
			ft_putstr_color(", col. ", COL_LIGHT_RED);
			ft_putnbr(i + 1);
			ft_putstr_color(": ", COL_LIGHT_RED);
			fdf_errors("Invalid file.\n");
		}
		++i;
	}
}

int		add_line(t_file *file, char *str, int i)
{
	t_line *line;

	line = NULL;
	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return (-1);
	line->nb = i;
	line->line = ft_strdup(str);
	line->tab = NULL;
	line->len = 0;
	ft_lstadd_back(&(file->lines), ft_lstnew((void *)line, sizeof(t_line)));
	free(line);
	return (0);
}
