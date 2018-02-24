/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:30:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:55:19 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int c;

	c = 0;
	if (!f || !s)
		return ;
	while (s[c] != '\0')
	{
		f(c, &s[c]);
		c++;
	}
}
