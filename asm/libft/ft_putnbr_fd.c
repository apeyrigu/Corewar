/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:26:24 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:56:37 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int c;

	c = (long int)n;
	if (c < -2147483648 || c > 2147483647)
		ft_putchar_fd(48, fd);
	if (c < 0)
	{
		ft_putchar_fd('-', fd);
		c *= -1;
	}
	if (c >= 10)
		ft_putnbr_fd(c / 10, fd);
	ft_putchar_fd((c % 10) + 48, fd);
}
