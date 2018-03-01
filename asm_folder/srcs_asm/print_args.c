/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 03:27:40 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/01 01:03:36 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_ind(t_env *env, const char *str, int i)
{
	int		tab[1];

	if (str[i] == LABEL_CHAR)
	{
		tab[0] = (locate_label(env->label, &str[i + 1]));
		tab[0] = tab[0] - POS;
		tab[0] = (tab[0] >> 8 & 0x00ff00ff) | (0xff00ff00 & tab[0] << 8);
		write(FD, tab, 2);
	}
	else
	{
		if ((tab[0] = (int)ft_atoi_long(&str[i])) < 0)
			tab[0] += 65536;
		tab[0] = (tab[0] >> 8 & 0x00ff00ff) | (0xff00ff00 & tab[0] << 8);
		write(FD, tab, 2);
	}
}

void	print_dir2(t_env *env, const char *str, int i, int dir_size)
{
	int		tab[1];

	if (dir_size == 4)
	{
		if ((tab[0] = (int)ft_atoi_long(&str[i + 1])) < 0)
			tab[0] = 4294967296 + tab[0];
		tab[0] = switch_int(tab[0]);
		write(FD, tab, 4);
	}
	else if (dir_size == 2)
	{
		if ((tab[0] = (int)ft_atoi_long(&str[i + 1])) < 0)
			tab[0] = 65536 + tab[0];
		tab[0] = (tab[0] >> 8 & 0x00ff00ff) | (0xff00ff00 & tab[0] << 8);
		write(FD, tab, 2);
	}
}

void	print_dir(t_env *env, const char *str, int i, int dir_size)
{
	int		tab[1];

	if (str[i + 1] == LABEL_CHAR)
	{
		if (dir_size == 4)
		{
			tab[0] = locate_label(env->label, &str[i + 2]);
			tab[0] = tab[0] - POS;
			tab[0] = switch_int(tab[0]);
			write(FD, tab, 4);
		}
		else
		{
			tab[0] = locate_label(env->label, &str[i + 2]);
			tab[0] = tab[0] - POS;
			tab[0] = (tab[0] >> 8 & 0x00ff00ff) | (0xff00ff00 & tab[0] << 8);
			write(FD, tab, 2);
		}
	}
	else
		print_dir2(env, str, i, dir_size);
}

void	print_reg(t_env *env, const char *str, int *i)
{
	int		tab[1];

	while (str[*i] && str[*i] != 'r')
		(*i)++;
	tab[0] = ft_atoi(&str[*i + 1]);
	write(FD, tab, 1);
}

void	print_aff(t_env *env, const char *str)
{
	int		tab[1];
	int		i;

	tab[0] = 0x00000010;
	write(FD, tab, 1);
	i = 0;
	tab[0] = 0x40;
	write(FD, tab, 1);
	while (str[i] != 'r')
		i++;
	i++;
	tab[0] = ft_atoi(&str[i]);
	write(FD, tab, 1);
	POS += 3;
}
