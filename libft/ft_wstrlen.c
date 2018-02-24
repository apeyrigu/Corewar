/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:25:57 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 19:25:58 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_wstrlen(wchar_t *str)
{
	int i;
	int written;

	i = 0;
	written = 0;
	if (str)
	{
		while (str[i])
		{
			written += ft_wlen(str[i]);
			i++;
		}
	}
	return (written);
}
