/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 05:31:03 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:57:14 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			c;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	c = 0;
	if (s > d)
		while (c < len)
		{
			d[c] = s[c];
			c++;
		}
	else
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	return (dst);
}
