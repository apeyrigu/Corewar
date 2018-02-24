/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:09:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:54:35 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		c;
	char	*str;

	c = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[c] != '\0')
	{
		str[c] = f(c, (char)s[c]);
		c++;
	}
	str[c] = '\0';
	return (str);
}
