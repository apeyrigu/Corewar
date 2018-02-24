/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 04:43:29 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 14:51:19 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	while (i >= 0 && str[i] != c)
	{
		i--;
	}
	if (str[i] == c)
		return ((char *)&(str[i]));
	return (NULL);
}
