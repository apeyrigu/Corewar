/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:17:51 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/12 16:30:32 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	len(const char *str)
{
	unsigned long i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	i;
	unsigned long	j;
	char			*p;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if ((p = (char *)malloc(sizeof(char) * (len(s1) + len(s2)) + 1)) == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strcpy(p, s1);
	i = len(s1);
	j = 0;
	if (s2 != NULL)
	{
		while (s2[j])
		{
			p[i] = s2[j];
			j++;
			i++;
		}
	}
	p[i] = '\0';
	return (p);
}
