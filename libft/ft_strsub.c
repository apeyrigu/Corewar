/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:41:46 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/12 16:31:32 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned long	i;

	if (s != NULL)
	{
		if (len > 0)
		{
			ptr = (char *)malloc(sizeof(char) * (len) + 1);
			if (ptr == NULL)
				return (NULL);
			i = 0;
			while (s[i + start] && i < len)
			{
				ptr[i] = s[i + start];
				i++;
			}
			ptr[i] = '\0';
			return (ptr);
		}
		if (len == 0)
			return (ft_strdup(""));
	}
	return (NULL);
}
