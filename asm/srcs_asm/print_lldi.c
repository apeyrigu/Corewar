/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lldi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 01:53:49 by abassibe          #+#    #+#             */
/*   Updated: 2018/01/31 01:43:25 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void		print_lldi_dir(t_env *env, const char *str, int *i, int save)
{
	int		tab[1];

	if (is_dir_print(str, &*i))
	{
		tab[0] = 0xa4;
		write(FD, tab, 1);
		print_dir(env, str, save, 2);
		print_dir(env, str, *i, 2);
		POS += 7;
	}
	else
	{
		tab[0] = 0x94;
		write(FD, tab, 1);
		print_dir(env, str, save, 2);
		print_reg(env, str, &*i);
		(*i)++;
		POS += 6;
	}
}

static void		print_lldi_ind(t_env *env, const char *str, int *i, int save)
{
	int		tab[1];

	if (is_dir_print(str, &*i))
	{
		tab[0] = 0xe4;
		write(FD, tab, 1);
		print_ind(env, str, save);
		print_dir(env, str, *i, 2);
		POS += 7;
	}
	else
	{
		tab[0] = 0xd4;
		write(FD, tab, 1);
		print_ind(env, str, save);
		print_reg(env, str, &*i);
		(*i)++;
		POS += 6;
	}
}

static void		print_lldi_reg(t_env *env, const char *str, int *i, int save)
{
	int		tab[1];

	if (is_dir_print(str, &*i))
	{
		tab[0] = 0x64;
		write(FD, tab, 1);
		print_reg(env, str, &save);
		print_dir(env, str, *i, 2);
		POS += 6;
	}
	else
	{
		tab[0] = 0x54;
		write(FD, tab, 1);
		print_reg(env, str, &save);
		print_reg(env, str, &*i);
		(*i)++;
		POS += 5;
	}
}

static void		print_lldi2(t_env *env, const char *str, int *i, int save)
{
	if (is_ind_print(str, &*i))
	{
		save = *i;
		while (str[*i] != ',')
			(*i)++;
		(*i)++;
		print_lldi_ind(env, str, &*i, save);
	}
	else
	{
		while (str[*i] != 'r')
			(*i)++;
		save = *i;
		while (str[*i] != ',')
			(*i)++;
		(*i)++;
		print_lldi_reg(env, str, &*i, save);
	}
}

void			print_lldi(t_env *env, const char *str)
{
	int		tab[1];
	int		i;
	int		save;

	tab[0] = 0x0000000e;
	write(FD, tab, 1);
	i = 0;
	save = i;
	if (is_dir_print(str, &i))
	{
		save = i;
		while (str[i] != ',')
			i++;
		i++;
		print_lldi_dir(env, str, &i, save);
	}
	else
		print_lldi2(env, str, &i, save);
	print_reg(env, str, &i);
}
