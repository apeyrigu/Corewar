/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:35:15 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 14:21:05 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned long i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)str)[i] == (unsigned char)c)
			return (&((unsigned char*)str)[i]);
		i++;
	}
	return (NULL);
}
