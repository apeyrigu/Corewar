/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 04:40:54 by apeyrigu          #+#    #+#             */
/*   Updated: 2018/02/24 06:33:41 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		nb_digits(int k)
{
	int		i;

	i = 0;
	while (k != 0)
	{
		k /= 10;
		i++;
	}
	return (i);
}

int		d_dump(char **s, t_vm *vm, int i, t_flag *tmp)
{
	(void)tmp;
	if (!s[i + 1])
		error_args("-d at end without number");
	if (ft_strcmp("-d", s[i]) != 0)
		error_args("Wrong arg bitch");
	vm->debug = ft_atoi(s[i + 1]);
	if (nb_digits(vm->debug) != (int)ft_strlen(s[i + 1]))
		error_args("Wrong number with -d bitch");
	if (vm->debug < 10 || vm->debug > INT_MAX)
		error_args("Not a valid number");
	return (1);
}

int		flagvisu(char **s, t_vm *vm, int i, t_flag *tmp)
{
	(void)tmp;
	if (ft_strcmp(s[i], "-v") == 0)
		vm->ncurses_mode = 1;
	else
		error_args("Wrong arg");
	return (0);
}

int		nbcycles(char **s, t_vm *vm, int i, t_flag *tmp)
{
	char	*tmp2;

	(void)tmp;
	if (!s[i + 1])
		error_args("-dump at end without number");
	if (ft_strcmp(s[i], "-dump") == 0)
	{
		vm->max_cycles = ft_atoi(s[i + 1]);
		tmp2 = ft_itoa(vm->max_cycles);
		if (ft_strlen(s[i + 1]) != ft_strlen(tmp2) ||
				vm->max_cycles <= 0)
			error_args("Wrong Number With -dump or Number <= 0");
		ft_strdel(&tmp2);
	}
	else
		error_args("Wrong arg");
	return (1);
}

int		w_dump(char **s, t_vm *vm, int i, t_flag *tmp)
{
	(void)tmp;
	if (!s[i + 1])
		error_args("-w at end without number");
	if (ft_strcmp("-w", s[i]) != 0)
		error_args("Wrong arg bitch");
	vm->debug = ft_atoi(s[i + 1]);
	if (nb_digits(vm->debug) != (int)ft_strlen(s[i + 1]))
		error_args("Wrong number with -d bitch");
	if (vm->debug < 10 || vm->debug > INT_MAX)
		error_args("Not a valid number");
	vm->debug *= -1;
	return (1);
}
