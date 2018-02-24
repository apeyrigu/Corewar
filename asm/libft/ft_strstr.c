/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 00:34:58 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:53:51 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	if (*little == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		j = i;
		c = 0;
		while (big[j] == little[c])
		{
			j++;
			c++;
			if (little[c] == '\0')
				return ((char*)&big[i]);
		}
		i++;
	}
	return (NULL);
}
