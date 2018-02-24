/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:03:33 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 14:17:46 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr != NULL)
	{
		ft_bzero(ptr, size);
		return (ptr);
	}
	return (NULL);
}
