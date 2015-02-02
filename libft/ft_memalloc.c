/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:54:26 by fdeage            #+#    #+#             */
/*   Updated: 2014/03/19 20:41:23 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*new;
	char	*ptr;

	if (!(new = (void *)malloc(size * sizeof(void *))))
		return (NULL);
	ptr = (char *)new;
	while (size--)
		*ptr++ = (char)0;
	return (new);
}
