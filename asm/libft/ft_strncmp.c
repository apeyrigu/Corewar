/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 02:36:43 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:54:27 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			c;
	unsigned char	*str1;
	unsigned char	*str2;

	c = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((c < n - 1) && str1[c] != '\0' && str1[c] == str2[c])
	{
		if (str1[c] == '\0' && str2[c] == '\0')
			return (0);
		c++;
	}
	return (str1[c] - str2[c]);
}
