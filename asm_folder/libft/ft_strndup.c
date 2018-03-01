/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:09:47 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:54:21 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(const char *src, int len)
{
	int		c;
	char	*dst;

	c = 0;
	dst = ft_strnew(len);
	while (c != len)
	{
		dst[c] = src[c];
		c++;
	}
	dst[c] = '\0';
	return (dst);
}
