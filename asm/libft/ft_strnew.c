/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:45:45 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 07:42:55 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*m;
	size_t	c;

	c = 0;
	m = (char *)malloc(size + 1);
	if (m == NULL)
		return (NULL);
	while (c != size)
	{
		m[c] = '\0';
		c++;
	}
	m[c] = '\0';
	return (m);
}
