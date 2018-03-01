/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 05:19:20 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:57:39 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	t;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	t = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*s2++ = *s1++) == t)
			return (s2);
		i++;
	}
	return (NULL);
}
