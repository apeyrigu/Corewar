/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:38:12 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/12 16:30:53 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned long i;

	if (n == 0)
		return (1);
	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		if (!s1)
		{
			if (!s2)
				return (1);
			else
				return (0);
		}
		while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
			i++;
		if ((((unsigned char)s1[i]) - ((unsigned char)s2[i])) == 0)
			return (1);
	}
	return (0);
}
