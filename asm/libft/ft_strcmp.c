/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 01:31:24 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:55:44 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				c;
	unsigned char	*str1;
	unsigned char	*str2;

	c = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[c] != '\0' && str1[c] == str2[c])
	{
		c++;
		if (str1[c] == '\0' && str2[c] == '\0')
			return (0);
	}
	return (str1[c] - str2[c]);
}
