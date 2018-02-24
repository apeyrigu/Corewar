/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:01:34 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 17:54:12 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned long i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)str1)[i] = ((unsigned char*)str2)[i];
		i++;
	}
	return ((unsigned char*)str1);
}
