/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:31:57 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 22:42:33 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ptr;

	ptr = NULL;
	if (s != NULL && f != NULL)
		ptr = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (ptr != NULL && f != NULL)
	{
		i = 0;
		while (s[i])
		{
			ptr[i] = s[i];
			ptr[i] = f(ptr[i]);
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
