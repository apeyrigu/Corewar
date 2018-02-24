/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 01:35:50 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/06 03:46:23 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		locate_label(t_label *label, const char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (label)
	{
		if (ft_strnstr(str, label->label_name, ft_strlen(label->label_name)))
		{
			while (label->label_name[i] && str[i])
			{
				i++;
				if (!label->label_name[i] &&
						(((str[i] < 'a' || str[i] > 'z') &&
						(str[i] < '0' || str[i] > '9') &&
						str[i] != '_') || !str[i]))
					return (label->pos);
			}
			i = 0;
		}
		label = label->next;
	}
	return (0);
}

char	is_dir_print(const char *str, int *i)
{
	int		save;

	save = *i;
	while (str[*i] != '%')
	{
		if (!str[*i] || str[*i] == ',')
			break ;
		(*i)++;
	}
	if (str[*i] == '%')
		return (1);
	*i = save;
	return (0);
}

char	is_ind_print(const char *str, int *i)
{
	int		save;

	save = *i;
	while (str[*i] && str[*i] != ':' && str[*i] < 33 && str[*i] != 'r')
		(*i)++;
	while (str[*i] && str[*i] != ':' && str[*i] > 33 && (str[*i] < '0' ||
				str[*i] > '9') && str[*i] != 'r' && str[*i] != '-')
	{
		if (str[*i] == 'o' && str[*i + 1] == 'r')
			(*i) += 2;
		else
			(*i)++;
	}
	while (str[*i] && str[*i] != ':' && str[*i] < 33 && str[*i] != 'r')
		(*i)++;
	if (str[*i] == ':' || (str[*i] >= '0' && str[*i] <= '9') ||
			(str[*i] == '-' && (str[*i + 1] >= '0' && str[*i + 1] <= '9')))
		return (1);
	*i = save;
	return (0);
}
