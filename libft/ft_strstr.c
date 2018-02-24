/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 04:49:12 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 15:15:24 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned long i;
	unsigned long j;
	unsigned long backup;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			backup = i;
			while (haystack[i] == needle[j] && haystack[i] && needle[j])
			{
				i++;
				j++;
			}
			if (j == ft_strlen((char*)needle))
				return ((char *)&(haystack[backup]));
			i = backup;
		}
		i++;
	}
	return (NULL);
}
