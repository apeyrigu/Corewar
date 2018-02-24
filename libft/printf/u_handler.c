/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 04:21:22 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 20:23:37 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_unsigned_raw(unsigned long long n, int precis)
{
	unsigned long long	i;
	int					nb_d;
	char				ptr[ft_digits_un(n) + 1];

	if (precis == 0)
		return ;
	ptr[ft_digits_un(n)] = '\0';
	nb_d = ft_digits_un(n);
	if (n == 0)
		((n == 0) ? ft_strcpy(ptr, "0") : ft_strcpy(ptr, "2147483648"));
	else
	{
		i = 0;
		while (n != 0)
		{
			ptr[nb_d - i - 1] = (n % 10) + '0';
			n /= 10;
			i++;
		}
	}
	i = 0;
	while ((unsigned)nb_d + (i++) < (unsigned)((precis == -1) ? 0 : precis))
		write(1, "0", 1);
	ft_putstr(ptr);
}

char		disp_signe_un(unsigned long long data, t_fmt *fmt, char testmode)
{
	char useless;

	data++;
	testmode++;
	useless = fmt->main;
	fmt->main = useless;
	return (0);
}

int			p_unsigned(t_fmt *fmt, va_list list)
{
	int					padding;
	unsigned long long	data;
	int					written;

	written = 0;
	padding = 0;
	data = get_unsigned_arg(fmt, list);
	if (ft_is_in('0', fmt->variant) || ft_is_in('-', fmt->variant))
		disp_signe_un(data, fmt, 0);
	if (ft_is_in('-', fmt->variant))
		ft_unsigned_raw(data, fmt->precision);
	written += disp_padding_int(padding, fmt, data) - padding;
	if (!ft_is_in('0', fmt->variant))
		disp_signe_un(data, fmt, 0);
	if (!ft_is_in('-', fmt->variant))
		ft_unsigned_raw(data, fmt->precision);
	if (fmt->precision != 0)
	{
		if (fmt->precision > ft_digits_un(data))
			written += fmt->precision;
		else
			written += ft_digits_un(data);
	}
	return (written);
}
