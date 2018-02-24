/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:19:23 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 17:54:10 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long i;

	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		i = n - 1;
		while (i + 1)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			i--;
		}
	}
	return (dest);
}
