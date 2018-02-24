/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:22:31 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 19:23:15 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

int	ft_putwstr(wchar_t *str, int prc)
{
	int i;
	int written;

	prc = (prc == -1) ? 2147483647 : prc;
	i = 0;
	written = 0;
	if (str)
	{
		while (str[i] && (written + (ft_wlen(str[i]))) <= prc)
		{
			written += ft_putwchar(str[i]);
			i++;
		}
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (written);
}
