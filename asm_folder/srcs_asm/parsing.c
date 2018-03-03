/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:10:10 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/02 05:24:38 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char			nl_end_of_file(int fd)
{
	char	*str;

	str = ft_strnew(1);
	lseek(fd, -1, SEEK_END);
	read(fd, str, 1);
	if (*str != '\n')
	{
		ft_strdel(&str);
		write(2, "No new line at the end of the file\n", 35);
		return (0);
	}
	ft_strdel(&str);
	return (1);
}

char			label_verif(t_ulabel *ulabel, t_label *label)
{
	t_label		*tmp;

	tmp = label;
	if (!ulabel || !label)
		return (1);
	while (ulabel)
	{
		while (label)
		{
			if (!ft_strcmp(label->label_name, ulabel->label))
				break ;
			if (!label->next)
				return (0);
			label = label->next;
		}
		label = tmp;
		ulabel = ulabel->next;
	}
	return (1);
}

char			parseur_next(t_env *env, char *str)
{
	if (env->name == 0 || env->comment == 0)
	{
		if (!pars_name_comment(env, str))
			return (0);
	}
	else if (!pars_core(env, str))
		return (0);
	return (1);
}

char			parseur(t_env *env, const char *file_name)
{
	char	*str;
	int		value;

	if (!check_extend(file_name) || (env->fd = open(file_name, O_RDONLY)) == -1)
	{
		perror("");
		return (0);
	}
	env->file_name = ft_strdup(file_name);
	while ((value = get_next_line(env->fd, &str)) > 0)
	{
		if (!parseur_next(env, str) || env->champ_size > CHAMP_MAX_SIZE)
		{
			if (env->champ_size > CHAMP_MAX_SIZE)
				ft_printf("\"%s\" : Champion too big\n", file_name);
			ft_strdel(&str);
			return (0);
		}
		ft_strdel(&str);
	}
	ft_strdel(&str);
	if (value == -1 || !nl_end_of_file(env->fd) ||
			!label_verif(env->ulab, env->label))
		return (0);
	return (1);
}
