/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 20:35:35 by fdeage            #+#    #+#             */
/*   Updated: 2014/06/24 18:54:46 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_color(char const *s, const char *color)
{
	ft_putstr_color_fd(s, color, 1);
}

void	ft_putstr_color_fd(char const *s, const char *color, int fd)
{
	ft_putstr_fd(color, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(COL_RESET, fd);
}

void	ft_color_switch_fd(const char *color, int fd)
{
	ft_putstr_fd(color, fd);
}

void	ft_color_std_fd(int fd)
{
	ft_putstr_fd(COL_RESET, fd);
}
