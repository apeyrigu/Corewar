/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 00:58:42 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:54:03 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t l)
{
	int		d;
	size_t	c;
	char	*s;

	d = 0;
	c = 0;
	s = (char *)big;
	while (c <= l)
	{
		while ((big[c] == little[d] || little[d] == '\0') && c <= l)
		{
			if (little[d] == '\0')
				return (&s[c - d]);
			d++;
			c++;
		}
		if (big[c] == '\0')
			return (NULL);
		c++;
	}
	return (NULL);
}
