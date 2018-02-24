/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:15:25 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 15:13:08 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *ptr;

	ptr = (char*)malloc(sizeof(char) * size + 1);
	if (ptr != NULL)
	{
		bzero(ptr, size + 1);
		return (ptr);
	}
	return (NULL);
}
