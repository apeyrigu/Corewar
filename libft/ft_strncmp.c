/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 05:32:01 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/12 16:07:33 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned long i;

	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i] && i < n - 1)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
