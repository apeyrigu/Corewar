/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:40:55 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 15:23:26 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned long			i;
	const unsigned char		*s1;
	const unsigned char		*s2;

	s1 = (const unsigned char*)str1;
	s2 = (const unsigned char*)str2;
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((int)(s1[i] - s2[i]));
		i++;
	}
	return (0);
}
