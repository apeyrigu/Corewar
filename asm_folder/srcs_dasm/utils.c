/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 00:45:53 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/03 04:25:15 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dasm.h"

void	ft_error(const char *str, const int check)
{
	if (check == 0)
		ft_printf("%s\n", str);
	else
		perror("");
	exit(-1);
}

char	*creat_bin(const char *str)
{
	char	**tab;
	char	*tmp;

	tab = ft_strsplit(str, '.');
	tmp = ft_strjoin(tab[0], ".s");
	free(tab[0]);
	free(tab[1]);
	free(tab);
	return (tmp);
}

void	clear_buff(char *buff)
{
	int		i;

	i = -1;
	while (buff[++i])
		buff[i] = 0;
}

void	alloc_op(t_env *env)
{
	if (!(env->op = ft_memalloc(sizeof(char *) * 16)))
		exit(-1);
	env->op[0] = get_live;
	env->op[1] = get_ld;
	env->op[2] = get_st;
	env->op[3] = get_add;
	env->op[4] = get_sub;
	env->op[5] = get_and;
	env->op[6] = get_or;
	env->op[7] = get_xor;
	env->op[8] = get_zjmp;
	env->op[9] = get_ldi;
	env->op[10] = get_sti;
	env->op[11] = get_fork;
	env->op[12] = get_lld;
	env->op[13] = get_lldi;
	env->op[14] = get_lfork;
	env->op[15] = get_aff;
}

char	check_value_read(t_env *env, int value)
{
	if (value == -1)
	{
		perror("");
		return (0);
	}
	if (value == 0)
	{
		ERR = ft_strdup("Champion's size doesn't match with file's size");
		return (0);
	}
	return (1);
}
