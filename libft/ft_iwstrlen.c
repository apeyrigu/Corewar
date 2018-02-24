/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iwstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:18:38 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 19:20:40 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_iwstrlen(wchar_t *str, int prc)
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
			written += ft_wlen(str[i]);
			i++;
		}
	}
	else
		return (6);
	return (written);
}
