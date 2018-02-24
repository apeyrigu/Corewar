/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 05:45:25 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:57:28 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			c;

	c1 = (unsigned char *)s;
	c2 = (unsigned char *)s2;
	c = 0;
	if ((c1 == NULL && c2 == NULL) || n == 0)
		return (0);
	while ((c < n - 1) && c1[c] == c2[c])
		c++;
	return (c1[c] - c2[c]);
}
