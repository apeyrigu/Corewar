/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 05:11:40 by abassibe          #+#    #+#             */
/*   Updated: 2017/10/04 06:03:52 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	c;

	c = 0;
	while (c < n)
	{
		((char *)dst)[c] = ((char *)src)[c];
		c++;
	}
	return (dst);
}
