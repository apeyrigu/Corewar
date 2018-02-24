/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 04:40:54 by apeyrigu          #+#    #+#             */
/*   Updated: 2018/02/24 01:38:57 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		flagcolor(char **s, t_vm *vm, int i, t_flag *tmp)
{
	(void)vm;
	if (ft_strcmp("black", s[i + 1]) == 0)
		tmp->color = 1;
	else if (ft_strcmp("green", s[i + 1]) == 0)
		tmp->color = 2;
	else if (ft_strcmp("blue", s[i + 1]) == 0)
		tmp->color = 3;
	else if (ft_strcmp("white", s[i + 1]) == 0)
		tmp->color = 4;
	else
		error_args("Wrong color (black green blue white)");
	return (1);
}

int		flagnumber(char **s, t_vm *vm, int i, t_flag *tmp)
{
	(void)vm;
	if (tmp->num != 0)
		error_args("Two -n 1 champ");
	if (!s[i + 1])
		error_args("-n at end without number");
	if (ft_strcmp(s[i], "-n") == 0)
	{
		tmp->num = ft_atoi(s[i + 1]);
		if (ft_strlen(s[i + 1]) != 1 || !(ft_strchr("1234", s[i + 1][0])))
			error_args("Wrong Number With -n (1-4 player)");
	}
	else
		error_args("Wrong arg");
	return (1);
}
