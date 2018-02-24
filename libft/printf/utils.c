/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 04:25:27 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 20:32:18 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		last_return(char *num)
{
	int j;

	if (num)
	{
		j = ft_atoi(num);
		free(num);
		return (j);
	}
	return (-1);
}

int		freset(char **this, char *that)
{
	if (*this)
		free(*this);
	*this = that;
	return (1);
}

int		get_last_number(char *str, char get_precision, int nbr)
{
	int		i;
	int		j;
	char	*num;

	i = ft_strlen(str) - 1;
	num = NULL;
	j = i;
	while (i--)
	{
		if (ft_isdigit(str[i]))
			nbr = 1;
		else if (str[i] == '.' && get_precision &&
		freset(&num, ((nbr) ? ft_strsub(str, i + 1, j - i - 1) : NULL)))
			break ;
		else if ((nbr && str[i] != '.' && !get_precision))
		{
			freset(&num, ft_strsub(str, i + 1, j - i - 1));
			if (!(!get_precision && !ft_atoi(num)))
				break ;
		}
		else if (!(nbr = 0))
			j = i;
	}
	return (last_return(num));
}

char	*get_only(char *these, char *str)
{
	int		i;
	char	*bck;
	char	*ret;
	char	li[2];

	i = 0;
	ret = NULL;
	while (str[i++])
	{
		if (ft_is_in(str[i], these))
		{
			bck = ret;
			if (str[i] != '0' || ft_not_in_number(i, str))
			{
				li[0] = str[i];
				li[1] = '\0';
			}
			else
				li[0] = '\0';
			ret = ft_strjoin(ret, (char*)li);
			free(bck);
		}
	}
	return ((!ret) ? ft_strdup("") : ret);
}

char	disp_signe(double data, t_fmt *fmt, char testmode)
{
	if (data < 0)
	{
		if (!testmode)
			write(1, "-", 1);
		return (1);
	}
	if ((ft_is_in('+', fmt->variant) ||
		ft_is_in(' ', fmt->variant)) && data >= 0)
	{
		if (!testmode)
			write(1, (ft_is_in('+', fmt->variant)) ? "+" : " ", 1);
		return (1);
	}
	return (0);
}
