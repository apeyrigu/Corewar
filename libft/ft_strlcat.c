/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 03:35:08 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/12 12:59:24 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned long i;
	unsigned long j;
	unsigned long read_dest;

	i = 0;
	while (dest[i] && i < n)
		i++;
	read_dest = i;
	if (i == n)
		return (i + ft_strlen(src));
	j = 0;
	while (src[j] && i < n - 1)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	if (i < n)
		dest[i] = '\0';
	return (read_dest + ft_strlen(src));
}
