/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 04:22:58 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 20:21:37 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	disp_padding_ws(wchar_t *str, t_fmt *fmt)
{
	int		i;
	int		pc;
	char	c;

	pc = 0;
	if (str)
	{
		pc = ft_wstrlen(str);
		if ((int)ft_wstrlen(str) > ft_iwstrlen(str, fmt->precision))
			pc = ft_iwstrlen(str, fmt->precision);
	}
	if (ft_is_in('0', fmt->variant) && !ft_is_in('-', fmt->variant))
		c = '0';
	else
		c = ' ';
	i = 0;
	while (i + pc < fmt->minlen)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	p_wstring(t_fmt *fmt, va_list list)
{
	wchar_t	*data;
	int		written;
	int		reallen;

	written = 0;
	data = va_arg(list, wchar_t*);
	reallen = (ft_wstrlen(data));
	if (fmt->precision != -1 && fmt->precision < reallen)
		reallen = fmt->precision;
	if (!ft_is_in('-', fmt->variant) && fmt->minlen > reallen)
		written += disp_padding_ws(data, fmt);
	written += ft_putwstr(data, fmt->precision);
	if (ft_is_in('-', fmt->variant) && fmt->minlen > reallen)
		written += disp_padding_ws(data, fmt);
	return (written);
}

int	ft_putstr_c(const char *str, int precision)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] && i < ((precision == -1) ? 2147483647 : precision))
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	else if (precision != 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	return (i);
}

int	disp_padding_s(char *str, t_fmt *fmt)
{
	int		i;
	int		pc;
	char	c;

	pc = 0;
	if (str)
	{
		pc = ft_strlen(str);
		if (fmt->precision != -1 && (int)ft_strlen(str) > fmt->precision)
			pc = fmt->precision;
	}
	if (ft_is_in('0', fmt->variant) && !ft_is_in('-', fmt->variant))
		c = '0';
	else
		c = ' ';
	i = 0;
	while (i + pc < fmt->minlen)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	p_string(t_fmt *fmt, va_list list)
{
	char	*data;
	int		written;
	int		reallen;

	written = 0;
	if (fmt->modifier->sum == 0)
	{
		data = va_arg(list, char*);
		reallen = (ft_strlen(data));
		if (fmt->precision != -1 && fmt->precision < reallen)
			reallen = fmt->precision;
		if (!ft_is_in('-', fmt->variant) && fmt->minlen > reallen)
			written += disp_padding_s(data, fmt);
		written += ft_putstr_c(data, fmt->precision);
		if (ft_is_in('-', fmt->variant) && fmt->minlen > reallen)
			written += disp_padding_s(data, fmt);
		return (written);
	}
	return (p_wstring(fmt, list));
}
