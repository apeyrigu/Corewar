/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 19:12:02 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:55:28 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int c;

	c = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[c] == s2[c])
	{
		if (s1[c] == '\0')
			return (1);
		c++;
	}
	return (0);
}
