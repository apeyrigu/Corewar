/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:39:28 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:57:06 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_power(int nb, int power)
{
	int		c;
	int		i;

	c = 1;
	i = nb;
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	while (c < power)
	{
		i *= nb;
		c++;
	}
	return (i);
}
