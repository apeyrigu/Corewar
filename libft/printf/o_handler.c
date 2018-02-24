/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 04:22:20 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 04:22:21 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					di_o(unsigned long long k)
{
	int i;

	i = 0;
	if (k == 0)
		return (1);
	while (k != 0)
	{
		k /= 8;
		i++;
	}
	return (i);
}

int					disp_padding_oc(int pa, t_fmt *fmt, unsigned long long data)
{
	char	c;
	int		pc;

	pc = 0;
	if (ft_is_in('0', fmt->variant) && !ft_is_in('-', fmt->variant) &&
	((fmt->precision == -1) ? 2147483647 : fmt->precision) > fmt->minlen)
		c = '0';
	else
		c = ' ';
	if (fmt->precision >= di_o(data))
		pc = (fmt->precision - di_o(data));
	if (fmt->precision == 0 && !data)
		pc -= ft_digits(data);
	while (pa + pc + di_o(data) < fmt->minlen)
	{
		write(1, &c, 1);
		pa++;
	}
	return (pa);
}

void				ft_octal_raw(unsigned long long n, int precis, t_fmt *fmt)
{
	unsigned long long	i;
	int					nb_d;
	char				ptr[di_o(n) + 1];

	if (precis == 0 && !n && !ft_is_in('#', fmt->variant))
		return ;
	ptr[di_o(n)] = '\0';
	nb_d = di_o(n);
	if (n == 0)
		((n == 0) ? ft_strcpy(ptr, "0") : ft_strcpy(ptr, "2147483648"));
	else
	{
		i = 0;
		while (n != 0)
		{
			ptr[nb_d - i - 1] = (n % 8) + '0';
			n /= 8;
			i++;
		}
	}
	i = 0;
	while ((unsigned)nb_d + (i++) < (unsigned)((precis == -1) ? 0 : precis))
		write(1, "0", 1);
	ft_putstr(ptr);
}

unsigned long long	get_unsigned_arg(t_fmt *fmt, va_list list)
{
	if (fmt->modifier->sum == 0)
		return (va_arg(list, unsigned int));
	if (fmt->modifier->z > 0)
		return ((long long)va_arg(list, size_t));
	if (fmt->modifier->j > 0)
		return ((long long)va_arg(list, intmax_t));
	if (fmt->modifier->l == 1)
		return ((unsigned long)va_arg(list, unsigned long));
	if (fmt->modifier->l >= 2)
		return ((unsigned long long)va_arg(list, unsigned long long));
	if (fmt->modifier->h == 1)
		return ((unsigned short)va_arg(list, unsigned int));
	if (fmt->modifier->h >= 2)
		return ((unsigned char)va_arg(list, unsigned int));
	return (0);
}

int					p_octal(t_fmt *fmt, va_list list)
{
	int					padding;
	unsigned long long	data;
	int					written;

	written = 0;
	data = get_unsigned_arg(fmt, list);
	if (ft_is_in('#', fmt->variant) && data && fmt->precision <= di_o(data))
		fmt->precision = di_o(data) + 1;
	if (fmt->precision == 0 && data != 0)
		fmt->precision = di_o(data) + 1;
	written += (padding = disp_signe_un(data, fmt, 1));
	if (ft_is_in('0', fmt->variant) || ft_is_in('-', fmt->variant))
		disp_signe_un(data, fmt, 0);
	if (ft_is_in('-', fmt->variant))
		ft_octal_raw(data, fmt->precision, fmt);
	written += disp_padding_oc(padding, fmt, data) - padding;
	if (!ft_is_in('0', fmt->variant) && !ft_is_in('-', fmt->variant))
		disp_signe_un(data, fmt, 0);
	if (!ft_is_in('-', fmt->variant))
		ft_octal_raw(data, fmt->precision, fmt);
	if (!(!fmt->precision && !data) ||
	(!fmt->precision && !data && ft_is_in('#', fmt->variant)))
		written += (fmt->precision > di_o(data)) ? fmt->precision : di_o(data);
	return (written);
}
