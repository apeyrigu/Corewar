/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:26:48 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 15:18:40 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char				is_sep(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static unsigned long	get_f(const char *str)
{
	unsigned long i;

	i = ft_strlen(str) - 1;
	while (i + 1)
	{
		if (!is_sep(str[i]))
			return (i);
		i--;
	}
	return (0);
}

char					*ft_strtrim(char const *s)
{
	unsigned long	i;
	unsigned long	f;
	unsigned long	j;
	char			*p;

	if (s == NULL)
		return (NULL);
	i = 0;
	f = get_f(s);
	while (is_sep(s[i]) && s[i])
		i++;
	if (!s[i])
		return (ft_strdup(""));
	if ((p = (char *)malloc(sizeof(char) * (f + 1 - (i)) + 1)) == NULL)
		return (NULL);
	j = 0;
	while (s[i] && i <= f)
	{
		p[j] = s[i];
		j++;
		i++;
	}
	p[j] = '\0';
	return (p);
}
