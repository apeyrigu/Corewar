/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 01:21:10 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 14:17:59 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		i;
	int		retour;
	char	negatif;

	negatif = 0;
	i = 0;
	retour = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negatif = 1;
	if (negatif || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		retour = (retour * 10) + (str[i] - '0');
		i++;
	}
	if (negatif)
		retour *= -1;
	return (retour);
}
