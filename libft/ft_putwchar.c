/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:24:14 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 19:24:16 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

int	ft_putwchar(wchar_t chr)
{
	if (chr <= 127)
		ft_putchar(chr);
	else if (chr <= 2047)
	{
		ft_putchar((chr >> 6) | 192);
		ft_putchar(((chr & 63) | 128));
		return (2);
	}
	else if (chr <= 65535)
	{
		ft_putchar((chr >> 12) | 224);
		ft_putchar(((chr >> 6) & 63) | 128);
		ft_putchar(((chr & 63) | 128));
		return (3);
	}
	else if (chr <= 2097151)
	{
		ft_putchar((chr >> 18) | 240);
		ft_putchar(((chr >> 12) & 63) | 128);
		ft_putchar(((chr >> 6) & 63) | 128);
		ft_putchar(((chr & 63) | 128));
		return (4);
	}
	return (1);
}
