/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 05:17:45 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 15:19:52 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *hs, const char *needle, size_t len)
{
	unsigned long i;
	unsigned long j;
	unsigned long backup;

	i = 0;
	if (*needle == '\0')
		return ((char*)hs);
	while (hs[i] && i < len)
	{
		j = 0;
		if (hs[i] == needle[j])
		{
			backup = i;
			while (hs[i] == needle[j] && hs[i] && needle[j] && i < len)
			{
				i++;
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)&(hs[backup]));
			i = backup;
		}
		i++;
	}
	return (NULL);
}
