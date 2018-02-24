/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 04:21:36 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 20:11:43 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	disp_padding_c(int padding, t_fmt *fmt, unsigned char data)
{
	char	c;
	int		bckpad;

	bckpad = padding;
	data++;
	if (ft_is_in('0', fmt->variant) && !ft_is_in('-', fmt->variant))
		c = '0';
	else
		c = ' ';
	while (padding + 1 < fmt->minlen)
	{
		write(1, &c, 1);
		padding++;
	}
	return (padding - bckpad);
}

int	p_char(t_fmt *fmt, va_list list)
{
	unsigned char	data;
	int				written;

	written = 0;
	if (fmt->modifier->l == 0)
	{
		data = (unsigned char)va_arg(list, int);
		if (ft_is_in('-', fmt->variant) && (written++ != -1))
			write(1, &data, 1);
		written += disp_padding_c(0, fmt, data);
		if (!ft_is_in('-', fmt->variant) && (written++ != -1))
			write(1, &data, 1);
	}
	else if (fmt->modifier->l >= 1)
		return (p_wchar(fmt, list));
	return (written);
}

int	p_wchar(t_fmt *fmt, va_list list)
{
	wchar_t	data;
	int		written;

	written = 0;
	data = va_arg(list, wchar_t);
	if (ft_is_in('-', fmt->variant))
		written += ft_putwchar(data);
	written += disp_padding_c(ft_wlen(data) - 1, fmt, 'k');
	if (!ft_is_in('-', fmt->variant))
		written += ft_putwchar(data);
	return (written);
}
