/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 02:07:24 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/03 04:20:48 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_tab(char **str, char **tab, int i)
{
	int		j;

	j = -1;
	while (++j < i)
		ft_strdel(&str[j]);
	free(tab);
}

void	free_operator(t_env *env)
{
	int		i;

	i = -1;
	while (++i < 16)
		ft_strdel(&env->op[i]);
	free_struct(env);
	free(env);
}

void	free_struct(t_env *env)
{
	t_label		*tmp;
	t_ulabel	*tmp2;

	while (env->label)
	{
		tmp = env->label->next;
		ft_strdel(&env->label->label_name);
		free(env->label);
		env->label = tmp;
	}
	while (env->ulab)
	{
		tmp2 = env->ulab->next;
		ft_strdel(&env->ulab->label);
		free(env->ulab);
		env->ulab = tmp2;
	}
	ft_strdel(&env->bin_name);
	ft_strdel(&env->file_name);
}
