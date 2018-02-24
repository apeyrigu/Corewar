/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 22:59:23 by pcluchet          #+#    #+#             */
/*   Updated: 2018/02/24 03:50:45 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	do_or(t_vm *vm, int *params, t_process *process, int totaloffset)
{
	int result;

	totaloffset++;
	result = params[1] | params[2];
	if (params[3] > 0 && params[3] < REG_NUMBER + 1)
	{
		check_debug(vm, process->process_id, 7, params);
		write_reg(process, result, params[3]);
	}
	process->carry = !result;
}

void	decode_or(t_vm *vm, t_process *process)
{
	int prs[4];

	if (process->cycles_to_go == 0)
	{
		process->offset = 0;
		if (acquire_params(vm, process, 7, prs))
		{
			do_or(vm, prs, process, process->offset);
		}
		process->pc_index += process->offset + 2;
		process->cycles_to_go = -1;
		set_cycles_to_go(vm, process);
	}
	else
		process->cycles_to_go--;
}

void	do_st(t_vm *vm, int *params, t_process *process)
{
	int playerid;
	int i;

	playerid = process->num_player;
	i = 0;
	while (i < 4)
	{
		single_access(vm, PCID + (params[2] % IDX_MOD) + i,
		get_bytes_n(i + 1, params[1]), playerid);
		i++;
	}
	check_debug(vm, process->process_id, 3, params);
}

void	decode_st(t_vm *vm, t_process *process)
{
	int prs[4];

	if (process->cycles_to_go == 0)
	{
		process->offset = 0;
		if (acquire_params(vm, process, 3, prs))
		{
			do_st(vm, prs, process);
		}
		process->pc_index += process->offset + 2;
		process->cycles_to_go = -1;
		set_cycles_to_go(vm, process);
	}
	else
		process->cycles_to_go--;
}
