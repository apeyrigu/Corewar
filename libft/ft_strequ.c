/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:50:43 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 15:20:47 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

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
		while (s1[i] == s2[i] && s1[i] && s2[i])
			i++;
		if ((((unsigned char)s1[i]) - ((unsigned char)s2[i])) == 0)
			return (1);
	}
	return (0);
}
