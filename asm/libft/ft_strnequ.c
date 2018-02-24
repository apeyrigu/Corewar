/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 19:20:36 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:54:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t c;

	c = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n == 0)
		return (1);
	while (s1[c] == s2[c] && c < n)
	{
		if (s1[c] == '\0')
			return (1);
		if (s1[c] == s2[c] && c == n - 1)
			return (1);
		c++;
	}
	return (0);
}
