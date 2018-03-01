/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 00:08:21 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:54:00 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		d;

	p = (char *)s;
	d = ft_strlen(p);
	while (d >= 0)
	{
		if (p[d] == c)
			return (&p[d]);
		d--;
	}
	return (NULL);
}
