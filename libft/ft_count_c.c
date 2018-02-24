/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:16:57 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 19:20:00 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_count_c(char c, char *str, char not_at_end)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (!not_at_end)
		{
			if (str[i] == c)
				cpt++;
		}
		else if (str[i] == c && str[i + 1])
			cpt++;
		i++;
	}
	return (cpt);
}
