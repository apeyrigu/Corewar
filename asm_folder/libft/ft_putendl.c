/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 09:09:06 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:56:52 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putendl(char const *s)
{
	int c;

	c = 0;
	if (!(s))
		return ;
	while (s[c] != '\0')
	{
		ft_putchar(s[c]);
		c++;
	}
	ft_putchar('\n');
}
