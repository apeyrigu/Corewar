/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 02:53:50 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/23 04:35:51 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	blank_check(const char *str, int c)
{
	while (str[c] == '\n' || str[c] == '\t' || str[c] == '\v' || str[c] == ' '
			|| str[c] == '\f' || str[c] == '\r')
		c++;
	return (c);
}

static int	min_max_val(const char *str, int c, unsigned int k, int p)
{
	int				ret;

	ret = 1;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			p = 1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		k *= 10;
		k += str[c] - 48;
		c++;
	}
	if (p == 1 && k > 2147483648)
		return (0);
	if (p == 0 && k > 2147483647)
		return (-1);
	if (p == 1)
		ret = k * -1;
	else
		ret = k;
	return (ret);
}

int			ft_atoi(const char *str)
{
	int				c;
	int				ret;
	int				p;
	unsigned int	k;

	c = 0;
	k = 0;
	p = 0;
	c = blank_check(str, c);
	ret = min_max_val(str, c, k, p);
	return (ret);
}
