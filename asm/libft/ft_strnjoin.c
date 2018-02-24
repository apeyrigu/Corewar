/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:50:47 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:54:07 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int len)
{
	char	*join;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	join = ft_strnew((int)ft_strlen(s2) + len + 1);
	i = 0;
	j = 0;
	while (i < len)
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	return (join);
}
