/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:24:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:58:25 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		itoa_neg(long int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char			*ft_itoa_long(long int n)
{
	long int	tmp;
	int			len;
	int			neg;
	char		*str;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	tmp = n;
	len = 2;
	neg = 0;
	itoa_neg(&n, &neg);
	while (tmp /= 10)
		len++;
	len += neg;
	str = ft_strnew(len);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
