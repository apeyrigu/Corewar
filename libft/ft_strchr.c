/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 04:39:11 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 15:10:32 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return ((char *)&(str[i]));
	return (NULL);
}
