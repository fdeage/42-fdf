/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:44:48 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/02 14:13:11 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

static int	cmp(char c, char const *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		++str;
	}
	return (0);
}

static int	n(const char *s1, const char *s2)
{
	int	word;

	word = 0;
	while (*s1)
	{
		if (cmp(*s1, s2) != 1)
			++word;
		while (cmp(*s1, s2) != 1 && *s1 != 0)
			++s1;
		while (cmp(*s1, s2) == 1)
			++s1;
	}
	return (word);
}

static int	split_line(t_line *line, char *s2)
{
	int		start;
	int		word;
	int		i;

	line->len = n(line->line, s2);
	if (!(line->line) || !(line->tab = (int *)ft_memalloc(sizeof(int)
		* line->len)))
		return (-1);
	check_line(line->line, line->nb);
	word = -1;
	i = 0;
	while (line->line[i])
	{
		if (cmp(line->line[i], s2) != 1)
			++word;
		start = i;
		while (cmp(line->line[i], s2) != 1 && line->line[i])
			++i;
		if (word >= 0)
			line->tab[word] = ft_atoi(&line->line[start]);
		while (cmp(line->line[i], s2) == 1)
			++i;
	}
	return (0);
}

static int	split_file(t_file *file)
{
	char	s2[3];
	size_t	i;
	t_list	*tmp;

	s2[0] = ' ';
	s2[1] = '\t';
	s2[2] = '\0';
	tmp = file->lines;
	i = 0;
	while (i < file->nb_line && tmp)
	{
		if (split_line((t_line *)(tmp->content), s2) == -1)
			return (-1);
		tmp = tmp->next;
		++i;
	}
	return (0);
}

int			read_tab(t_file *file)
{
	int		i;
	char	*str;

	str = NULL;
	file->lines = NULL;
	i = 0;
	while ((file->ret = get_next_line(file->fd, &str)) > 0 || *str)
	{
		if (str && !(*str))
		{
			free(str);
			continue;
		}
		if (add_line(file, str, i))
			return (-1);
		free(str);
		++i;
	}
	if (file->ret == -1)
		return (-1);
	free(str);
	file->nb_line = i;
	if (i == 0 || split_file(file) == -1)
		return (-1);
	return (0);
}
