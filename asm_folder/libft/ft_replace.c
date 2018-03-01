/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 23:46:32 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:56:13 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

char	*ft_replace(char *str, char c1, char c2)
{
	int		c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] == c1)
			str[c] = c2;
		c++;
	}
	return (str);
}
