/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 19:26:46 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 07:44:01 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsubf(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	c;

	c = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (c != len)
	{
		str[c] = s[start];
		c++;
		start++;
	}
	str[c] = '\0';
	free((void *)s);
	return (str);
}
