/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kingdom_hearts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 02:58:23 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/06 02:52:19 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_op(t_env *env, const char *str)
{
	int			i;
	t_label		*tmp;

	i = -1;
	tmp = env->label;
	while (++i < 16)
	{
		while (tmp)
		{
			if (ft_strnstr(str, tmp->label_name, ft_strlen(tmp->label_name)))
				if (str[ft_strlen(tmp->label_name)] == ':')
					str += ft_strlen(tmp->label_name) + 2;
			tmp = tmp->next;
			while (*str && *str < 33)
				str++;
		}
		if ((ft_strlen(str) >= 2) && (str[2] == 'i' && i < 3) &&
				ft_strnstr(str, env->op[i], ft_strlen(env->op[i])))
			;
		else if (ft_strnstr(str, env->op[i], ft_strlen(env->op[i])))
			env->opf[i](env, str);
		tmp = env->label;
	}
}

char	is_label(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ':')
		i++;
	if (!str[i])
		return (0);
	i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] > 32)
			return (0);
		i++;
	}
	return (1);
}

void	print_core(t_env *env, const char *str)
{
	alloc_op_functions(env);
	while (*str < 33)
		str++;
	if (is_label(str))
		return ;
	else
		print_op(env, str);
}

void	dispatcher(t_env *env, const char *str)
{
	if (comment_or_empty(str))
		return ;
	if (env->name == 0 || env->comment == 0)
		print_name_comment(env, str);
	else
		print_core(env, str);
}

void	kingdom_hearts(t_env *env)
{
	char	*str;

	env->tab[0] = 0xf383ea00;
	env->bin_name = creat_bin(env->file_name);
	if ((FD = open(env->bin_name, O_CREAT | O_RDWR, 0777)) == -1)
		ft_error("", 1);
	write(FD, env->tab, 4);
	lseek(env->fd, 0, SEEK_SET);
	env->name = 0;
	env->comment = 0;
	while (get_next_line(env->fd, &str))
	{
		dispatcher(env, str);
		ft_strdel(&str);
	}
	ft_strdel(&str);
}
