/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:42:30 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/15 20:32:55 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_digits(int k)
{
	int i;

	i = 0;
	while (k != 0)
	{
		k /= 10;
		i++;
	}
	return (i);
}

void		ft_putnbr(int n)
{
	int		i;
	int		nb_d;
	char	ptr[nb_digits(n) + ((n < 0) ? 1 : 0) + 1];
	char	neg;

	ptr[nb_digits(n) + ((n < 0) ? 1 : 0)] = '\0';
	if (n == 0 || n == -2147483647 - 1)
		return ((n == 0) ? ft_putstr("0") : ft_putstr("-2147483648"));
	neg = (n < 0) ? 1 : 0;
	if (n < 0)
		n = -n;
	nb_d = nb_digits(n);
	i = 0;
	while (n != 0)
	{
		ptr[nb_d - i + neg - 1] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (neg)
		ptr[0] = '-';
	ft_putstr(ptr);
}
