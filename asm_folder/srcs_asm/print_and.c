/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 01:53:49 by abassibe          #+#    #+#             */
/*   Updated: 2018/01/31 07:34:06 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void		print_and_dir(t_env *env, const char *str, int *i, int save)
{
	if (is_dir_print(str, &*i))
	{
		env->tab[0] = 0xa4;
		write(FD, env->tab, 1);
		print_dir(env, str, save, 4);
		print_dir(env, str, *i, 4);
		POS += 11;
	}
	else if (is_ind_print(str, &*i))
	{
		env->tab[0] = 0xb4;
		write(FD, env->tab, 1);
		print_dir(env, str, save, 4);
		print_ind(env, str, *i);
		POS += 9;
	}
	else
	{
		env->tab[0] = 0x94;
		write(FD, env->tab, 1);
		print_dir(env, str, save, 4);
		print_reg(env, str, &*i);
		(*i)++;
		POS += 8;
	}
}

static void		print_and_ind(t_env *env, const char *str, int *i, int save)
{
	if (is_dir_print(str, &*i))
	{
		env->tab[0] = 0xe4;
		write(FD, env->tab, 1);
		print_ind(env, str, save);
		print_dir(env, str, *i, 4);
		POS += 9;
	}
	else if (is_ind_print(str, &*i))
	{
		env->tab[0] = 0xf4;
		write(FD, env->tab, 1);
		print_ind(env, str, save);
		print_ind(env, str, *i);
		POS += 7;
	}
	else
	{
		env->tab[0] = 0xd4;
		write(FD, env->tab, 1);
		print_ind(env, str, save);
		print_reg(env, str, &*i);
		(*i)++;
		POS += 6;
	}
}

static void		print_and_reg(t_env *env, const char *str, int *i, int save)
{
	if (is_dir_print(str, &*i))
	{
		env->tab[0] = 0x64;
		write(FD, env->tab, 1);
		print_reg(env, str, &save);
		print_dir(env, str, *i, 4);
		POS += 8;
	}
	else if (is_ind_print(str, &*i))
	{
		env->tab[0] = 0x74;
		write(FD, env->tab, 1);
		print_reg(env, str, &save);
		print_ind(env, str, *i);
		POS += 6;
	}
	else
	{
		env->tab[0] = 0x54;
		write(FD, env->tab, 1);
		print_reg(env, str, &save);
		print_reg(env, str, &*i);
		(*i)++;
		POS += 5;
	}
}

static void		print_and2(t_env *env, const char *str, int *i, int save)
{
	if (is_ind_print(str, &*i))
	{
		save = *i;
		while (str[*i] != ',')
			(*i)++;
		(*i)++;
		print_and_ind(env, str, &*i, save);
	}
	else
	{
		while (str[*i] > 32)
			(*i)++;
		while (str[*i] != 'r')
			(*i)++;
		save = *i;
		while (str[*i] != ',')
			(*i)++;
		(*i)++;
		print_and_reg(env, str, &*i, save);
	}
}

void			print_and(t_env *env, const char *str)
{
	int		tab[1];
	int		i;
	int		save;

	tab[0] = 0x00000006;
	write(FD, tab, 1);
	i = 0;
	save = i;
	if (is_dir_print(str, &i))
	{
		save = i;
		while (str[i] != ',')
			i++;
		i++;
		print_and_dir(env, str, &i, save);
	}
	else
		print_and2(env, str, &i, save);
	print_reg(env, str, &i);
}
