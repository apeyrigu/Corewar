/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 22:59:14 by pcluchet          #+#    #+#             */
/*   Updated: 2018/02/24 03:50:30 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	do_sub(t_vm *vm, int *params, t_process *process)
{
	int result;

	vm++;
	result = params[1] - params[2];
	if (params[3] > 0 && params[3] < REG_NUMBER + 1)
	{
		write_reg(process, result, params[3]);
	}
	process->carry = !result;
}

void	decode_sub(t_vm *vm, t_process *process)
{
	int prs[4];

	if (process->cycles_to_go == 0)
	{
		process->offset = 0;
		if (acquire_params(vm, process, 5, prs))
		{
			do_sub(vm, prs, process);
		}
		process->pc_index += process->offset + 2;
		process->cycles_to_go = -1;
		set_cycles_to_go(vm, process);
	}
	else
		process->cycles_to_go--;
}

void	do_ldi(t_vm *vm, int *params, t_process *process, int totaloffset)
{
	int adress;
	int read;

	totaloffset++;
	adress = (params[1] + params[2]) % IDX_MOD;
	read = read_n_oct(vm, (process->pc_index + adress) % MEM_SIZE, 4);
	if (params[3] > 0 && params[3] < REG_NUMBER + 1)
	{
		check_debug(vm, process->process_id, 11, params);
		write_reg(process, read, params[3]);
	}
}

void	decode_ldi(t_vm *vm, t_process *process)
{
	int prs[4];

	if (process->cycles_to_go == 0)
	{
		process->offset = 0;
		if (acquire_params(vm, process, 10, prs))
		{
			do_ldi(vm, prs, process, process->offset);
		}
		process->pc_index += process->offset + 2;
		process->cycles_to_go = -1;
		set_cycles_to_go(vm, process);
	}
	else
		process->cycles_to_go--;
}
