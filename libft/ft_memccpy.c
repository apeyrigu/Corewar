/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:06:55 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/12 13:17:25 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	unsigned long i;

	i = 0;
	if (n)
	{
		while (i < n)
		{
			((unsigned char*)str1)[i] = ((unsigned char*)str2)[i];
			if (((unsigned char*)str2)[i] == (unsigned char)c)
				return ((unsigned char*)&str1[i + 1]);
			i++;
		}
	}
	return (NULL);
}
