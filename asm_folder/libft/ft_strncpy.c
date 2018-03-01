/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:48:49 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:54:24 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t c;

	c = 0;
	while (src[c] != '\0' && c < n)
	{
		dst[c] = src[c];
		c++;
	}
	while (c < n)
	{
		dst[c] = '\0';
		c++;
	}
	return (dst);
}
