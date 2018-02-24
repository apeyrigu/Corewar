/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_in_number.C                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:21:41 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 20:04:47 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

char	ft_not_in_number(int index, char *str)
{
	int		i;
	char	nbr;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && str[i] != '0')
			nbr = 1;
		if (!ft_isdigit(str[i]))
			nbr = 0;
		if (index == i && nbr)
			return (0);
		i++;
	}
	return (1);
}
