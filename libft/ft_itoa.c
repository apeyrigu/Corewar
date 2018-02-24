/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:39:42 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/08 19:26:32 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

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

char		*ft_itoa(int n)
{
	int		i;
	int		nb_d;
	char	*ptr;
	char	neg;

	if (n == 0 || n == -2147483647 - 1)
		return ((n == 0) ? ft_strdup("0") : ft_strdup("-2147483648"));
	neg = (n < 0) ? 1 : 0;
	if (n < 0)
		n = -n;
	nb_d = nb_digits(n);
	if ((ptr = ft_strnew(nb_d + neg)) == NULL)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		ptr[nb_d - i + neg - 1] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (neg)
		ptr[0] = '-';
	return (ptr);
}
