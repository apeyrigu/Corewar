/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 05:26:10 by pcluchet          #+#    #+#             */
/*   Updated: 2017/09/11 10:15:12 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *str1, const char *str2)
{
	int i;

	i = 0;
	if (!str1 || !str2)
		return (-1);
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return (((unsigned char)str1[i]) - ((unsigned char)str2[i]));
}
