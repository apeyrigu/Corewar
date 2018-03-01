/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 05:38:02 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:57:32 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c2;
	size_t			k;

	str = (unsigned char *)s;
	c2 = (unsigned char)c;
	k = 0;
	while (k < n)
	{
		if (str[k] == c2)
			return (str + k);
		k++;
	}
	return (NULL);
}
