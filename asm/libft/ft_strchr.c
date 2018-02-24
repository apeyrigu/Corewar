/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 23:38:21 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 07:42:13 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		p;
	char	*d;

	p = 0;
	d = (char*)s;
	while (d[p] != '\0')
	{
		if (d[p] == (char)c)
			return (&d[p]);
		p++;
	}
	if (c == '\0')
		return (&d[p]);
	else
		return (NULL);
}
