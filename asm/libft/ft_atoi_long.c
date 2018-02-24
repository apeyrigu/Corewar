/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 02:53:50 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/30 06:01:38 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		blank_check(const char *str, int c)
{
	while (str[c] == '\n' || str[c] == '\t' || str[c] == '\v' || str[c] == ' '
			|| str[c] == '\f' || str[c] == '\r')
		c++;
	return (c);
}

static long int	min_max_val(const char *str, int c, unsigned long int k, int p)
{
	long int			ret;

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
	if (p == 1)
		ret = k * -1;
	else
		ret = k;
	return (ret);
}

long			ft_atoi_long(const char *str)
{
	int					c;
	long int			ret;
	int					p;
	unsigned long int	k;

	c = 0;
	k = 0;
	p = 0;
	c = blank_check(str, c);
	ret = min_max_val(str, c, k, p);
	return (ret);
}
