/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 05:18:30 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/02 05:26:21 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	check_extend(const char *str)
{
	int		i;

	i = ft_strlen(str);
	if (str[i - 2] != '.' || str[i - 1] != 's')
	{
		write(2, "Wrong extension\n", 16);
		return (0);
	}
	return (1);
}

char	*creat_bin(const char *str)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strndup(str, ft_strlen(str) - 2);
	ret = ft_strjoin(tmp, ".cor");
	ft_strdel(&tmp);
	return (ret);
}

void	alloc_operators(t_env *env)
{
	env->op[0] = ft_strdup("live");
	env->op[1] = ft_strdup("ld");
	env->op[2] = ft_strdup("st");
	env->op[3] = ft_strdup("add");
	env->op[4] = ft_strdup("sub");
	env->op[5] = ft_strdup("and");
	env->op[6] = ft_strdup("or");
	env->op[7] = ft_strdup("xor");
	env->op[8] = ft_strdup("zjmp");
	env->op[9] = ft_strdup("ldi");
	env->op[10] = ft_strdup("sti");
	env->op[11] = ft_strdup("fork");
	env->op[12] = ft_strdup("lld");
	env->op[13] = ft_strdup("lldi");
	env->op[14] = ft_strdup("lfork");
	env->op[15] = ft_strdup("aff");
}

void	alloc_op_functions(t_env *env)
{
	env->opf[0] = print_live;
	env->opf[1] = print_ld;
	env->opf[2] = print_st;
	env->opf[3] = print_add;
	env->opf[4] = print_sub;
	env->opf[5] = print_and;
	env->opf[6] = print_or;
	env->opf[7] = print_xor;
	env->opf[8] = print_zjmp;
	env->opf[9] = print_ldi;
	env->opf[10] = print_sti;
	env->opf[11] = print_fork;
	env->opf[12] = print_lld;
	env->opf[13] = print_lldi;
	env->opf[14] = print_lfork;
	env->opf[15] = print_aff;
}
