/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 00:48:44 by abassibe          #+#    #+#             */
/*   Updated: 2018/01/25 05:47:35 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		switch_int(int octet)
{
	int		tmp;

	tmp = octet;
	tmp = (tmp >> 16 & 0x0000ffff) | (0xffff0000 & tmp << 16);
	tmp = (tmp >> 8 & 0x00ff00ff) | (0xff00ff00 & tmp << 8);
	return (tmp);
}

void	print_name(t_env *env, const char *str)
{
	int		i;
	int		limit;
	int		tab[1];

	i = 5;
	limit = -1;
	while (str[i] && str[i] != '"')
		i++;
	i++;
	while (str[i] && str[i] != '"')
	{
		tab[0] = str[i];
		write(FD, tab, 1);
		i++;
		limit++;
	}
	while (++limit < 128)
		write(FD, "\0", 1);
	write(FD, "\0\0\0\0", 4);
	tab[0] = switch_int(env->champ_size);
	write(FD, tab, 4);
}

void	print_comment(t_env *env, const char *str)
{
	int		i;
	int		limit;
	int		tab[1];

	i = 5;
	limit = -1;
	while (str[i] && str[i] != '"')
		i++;
	i++;
	while (str[i] && str[i] != '"')
	{
		tab[0] = str[i];
		write(FD, tab, 1);
		i++;
		limit++;
	}
	while (++limit < 2048)
		write(FD, "\0", 1);
	write(FD, "\0\0\0\0", 4);
}

void	print_name_comment(t_env *env, const char *str)
{
	while (*str && *str != '.')
		str++;
	if (!*str)
		return ;
	if (str[1] == 'n' && str[2] == 'a' && str[3] == 'm' && str[4] == 'e')
	{
		print_name(env, str);
		env->name = 1;
	}
	if (str[1] == 'c' && str[2] == 'o' && str[3] == 'm' && str[4] == 'm' &&
			str[5] == 'e' && str[6] == 'n' && str[7] == 't')
	{
		print_comment(env, str);
		env->comment = 1;
	}
}
