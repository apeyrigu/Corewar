/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:36:49 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/14 15:09:57 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strlenne(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char			*ft_strdup(char *src)
{
	char	*new;
	int		i;

	new = (char*)malloc(sizeof(char) * ft_strlenne(src) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
