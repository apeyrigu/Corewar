/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:24:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:58:19 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa_ulong(unsigned long int n)
{
	unsigned long int	tmp;
	int					len;
	int					neg;
	char				*str;

	tmp = n;
	len = 2;
	neg = 0;
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
