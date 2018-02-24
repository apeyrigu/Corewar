/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 07:07:49 by apeyrigu          #+#    #+#             */
/*   Updated: 2018/02/24 01:34:13 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				debug_mod(char **s, t_vm *vm, int i, t_flag *tmp)
{
	(void)tmp;
	if (ft_strcmp(s[i], "-s") != 0)
		error_args("Wrong arg dude\n");
	if (!s[i + 1])
		error_args("-s without number");
	if (vm->debug != 0)
		error_args("please only one -s\n");
	vm->debug = ft_atoi(s[i + 1]);
	if (ft_strlen(s[i + 1]) != 1 || vm->debug <= 0 || vm->debug > 5)
		error_args("Wrong number with -s\n");
	return (1);
}

void			show_op2(int proc, int op, int *arg)
{
	if (op == 11)
		ft_printf("P  %d | ldi %d %d r%d\n     | \
-> load from %d + %d = %d (with pc and mod %d)\n",
proc, arg[1], arg[2], arg[3], arg[1], arg[2], arg[1] + arg[2], arg[0]);
	if (op == 12)
		ft_printf("P  %d | sti %d %d %d\n     | \
-> store to %d + %d = %d (with pc and mod %d)\n",
proc, arg[4], arg[2], arg[3], arg[2], arg[3], arg[2] + arg[3], arg[0]);
	if (op == 13)
		ft_printf("P  %d | fork %d (%d)\n", proc, arg[0], arg[0] + arg[1]);
	if (op == 14)
		ft_printf("P  %d | lfork %d (%d)\n",
				proc, arg[0], 1024 * (arg[0] > 2048 ? 3 : arg[1]));
	if (op == 15)
		ft_printf("P  %d | lld %d r%d\n", proc, arg[1], arg[2]);
	if (op == 16)
		ft_printf("P  %d | lldi %d %d r%d\n     | \
-> load from %d + %d = %d (with pc and mod %d)\n",
	proc, arg[1], arg[2], arg[3], arg[1], arg[2], arg[1] + arg[2], arg[0]);
}

void			show_op(t_vm *vm, int proc, int op, int *arg)
{
	(void)vm;
	if (op <= 0)
		return ;
	else if (op > 10)
		show_op2(proc, op, arg);
	else if (op == 1)
		ft_printf("P  %d | live %d\n", proc, *arg);
	else if (op == 2)
		ft_printf("P  %d | ld %d r%d\n", proc, arg[1], arg[2]);
	else if (op == 3)
		ft_printf("P  %d | st r%d %d\n", proc, arg[1], arg[2]);
	else if (op == 4)
		ft_printf("P  %d | add r%d r%d r%d\n", proc, arg[1], arg[2], arg[3]);
	else if (op == 5)
		ft_printf("P  %d | sub r%d r%d r%d\n", proc, arg[1], arg[2], arg[3]);
	else if (op == 6)
		ft_printf("P  %d | and %d %d r%d\n", proc, arg[1], arg[2], arg[3]);
	else if (op == 7)
		ft_printf("P  %d | or %d %d r%d\n", proc, arg[1], arg[2], arg[3]);
	else if (op == 8)
		ft_printf("P  %d | xor %d %d r%d\n", proc, arg[1], arg[2], arg[3]);
	else if (op == 9)
		ft_printf("P  %d | zjmp %d OK\n", proc, arg[0]);
	else if (op == 10)
		ft_printf("P  %d | zjmp %d FAILED\n", proc, arg[0]);
}

static const	t_debug	g_bug[] =
{
	[1] = im_alive,
	[2] = show_cycle,
	[3] = show_op,
	[4] = death_mod,
};

void			check_debug2(t_vm *vm)
{
	if (vm->debug == vm->cycle)
	{
		dump_memory(vm);
		ft_printf("Memory dump at cycle %d\n", vm->debug);
		exit(0);
	}
}

void			check_debug(t_vm *vm, int proc, int op, int *arg)
{
	int i;

	i = 1;
	if (vm->debug == 0 || vm->ncurses_mode)
		return ;
	else if (vm->debug > 5)
	{
		check_debug2(vm);
		return ;
	}
	else if (vm->debug < 0)
	{
		while (((vm->debug * -1) * i) < 243659)
		{
			if ((vm->debug * -1 * i) == vm->cycle)
			{
				dump_memory(vm);
				sleep(5);
				return ;
			}
			i++;
		}
		return ;
	}
	g_bug[vm->debug](vm, proc, op, arg);
}
