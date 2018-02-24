/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:52:06 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/12 16:55:50 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned long	cnext(const char *str, unsigned long from, char c)
{
	unsigned long i;

	i = from;
	while (str[i] != c && str[i])
	{
		i++;
	}
	return (i);
}

static unsigned long	c_id(char const *s, char c)
{
	unsigned long i;
	unsigned long id;

	i = 0;
	id = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (cnext(s, i, c) != i)
		{
			id++;
			i = cnext(s, i, c);
		}
	}
	return (id);
}

char					**ft_strsplit(char const *s, char c)
{
	unsigned long	i;
	unsigned long	id;
	char			**ptr;

	id = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if ((ptr = (char **)malloc(sizeof(char*) * c_id(s, c) + 1)) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (cnext(s, i, c) != i)
		{
			if ((ptr[id] = ft_strsub(s, i, (cnext(s, i, c) - i))) == NULL)
				return (NULL);
			i = cnext(s, i, c);
			id++;
		}
	}
	ptr[id] = NULL;
	return (ptr);
}
