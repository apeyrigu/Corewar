/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 04:23:20 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 22:06:18 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_putnbr_raw(long long n, int precision)
{
	int		i;
	int		nb_d;
	char	ptr[ft_digits(n) + 1];

	if (precision == 0 && !n)
		return ;
	nb_d = ft_digits(n);
	if ((!(ptr[ft_digits(n)] = '\0') && !n) || n == -9223372036854775807 - 1)
		((!n) ? ft_strcpy(ptr, "0") : ft_strcpy(ptr, "9223372036854775808"));
	else
	{
		if (n < 0)
			n = -n;
		i = 0;
		while (n != 0)
		{
			ptr[nb_d - i - 1] = (n % 10) + '0';
			n /= 10;
			i++;
		}
	}
	i = 0;
	while (nb_d + (i++) < precision)
		write(1, "0", 1);
	ft_putstr(ptr);
}

int			disp_padding_int(int padding, t_fmt *fmt, long long data)
{
	char	c;
	int		pc;

	pc = 0;
	if (ft_is_in('0', fmt->variant) && !ft_is_in('-', fmt->variant) &&
	((fmt->precision == -1) ? 2147483647 : fmt->precision) > fmt->minlen)
		c = '0';
	else
		c = ' ';
	if (fmt->precision >= ft_digits(data))
		pc = (fmt->precision - ft_digits(data));
	if (fmt->precision == 0 && !data)
		pc -= ft_digits(data);
	while (padding + pc + ft_digits(data) < fmt->minlen)
	{
		write(1, &c, 1);
		padding++;
	}
	return (padding);
}

long long	get_arg(t_fmt *fmt, va_list list)
{
	if (fmt->modifier->sum == 0)
		return ((long long)va_arg(list, int));
	if (fmt->modifier->z > 0)
		return ((long long)va_arg(list, size_t));
	if (fmt->modifier->j > 0)
		return ((long long)va_arg(list, intmax_t));
	if (fmt->modifier->l == 1)
		return ((long long)va_arg(list, long));
	if (fmt->modifier->l >= 2)
		return ((long long)va_arg(list, long long));
	if (fmt->modifier->h == 1)
		return ((short)va_arg(list, int));
	if (fmt->modifier->h >= 2)
		return ((char)va_arg(list, int));
	return (0);
}

int			p_integer(t_fmt *fmt, va_list list)
{
	int			padding;
	long long	data;
	int			written;

	written = 0;
	data = get_arg(fmt, list);
	written += (padding = disp_signe(data, fmt, 1));
	if (ft_is_in('0', fmt->variant) || ft_is_in('-', fmt->variant))
		disp_signe(data, fmt, 0);
	if (ft_is_in('-', fmt->variant))
		ft_putnbr_raw(data, fmt->precision);
	written += disp_padding_int(padding, fmt, data) - padding;
	if (!ft_is_in('0', fmt->variant) && !ft_is_in('-', fmt->variant))
		disp_signe(data, fmt, 0);
	if (!ft_is_in('-', fmt->variant))
		ft_putnbr_raw(data, fmt->precision);
	if (!(fmt->precision == 0 && !data))
	{
		if (fmt->precision > ft_digits(data))
			written += fmt->precision;
		else
			written += ft_digits(data);
	}
	return (written);
}
