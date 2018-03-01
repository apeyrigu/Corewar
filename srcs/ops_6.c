/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 22:59:35 by pcluchet          #+#    #+#             */
/*   Updated: 2018/03/01 20:22:58 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	do_aff(t_vm *vm, int *params, t_process *process)
{
	process++;
	if (vm->aff == 1)
	{
		ft_printf("%c\n", params[1] % 256);
	}
}

void	decode_aff(t_vm *vm, t_process *process)
{
	int prs[4];

	if (process->cycles_to_go == 0)
	{
		process->offset = 0;
		if (acquire_params(vm, process, 16, prs))
		{
			do_aff(vm, prs, process);
		}
		process->pc_index += process->offset + 2;
		process->cycles_to_go = -1;
		set_cycles_to_go(vm, process);
	}
	else
		process->cycles_to_go--;
}

void	decode_xor(t_vm *vm, t_process *process)
{
	int prs[4];

	if (process->cycles_to_go == 0)
	{
		process->offset = 0;
		if (acquire_params(vm, process, 8, prs))
		{
			do_xor(vm, prs, process);
		}
		process->pc_index += process->offset + 2;
		process->cycles_to_go = -1;
		set_cycles_to_go(vm, process);
	}
	else
		process->cycles_to_go--;
}

void	do_lldi(t_vm *vm, int *params, t_process *process, int totaloffset)
{
	int adress;
	int read;

	totaloffset++;
	check_debug(vm, process->process_id, 15, params);
	adress = (params[1] + params[2]);
	read = read_n_oct(vm, process->pc_index + adress, 4);
	if (params[3] > 0 && params[3] < REG_NUMBER + 1)
	{
		write_reg(process, read, params[3]);
	}
	process->carry = !read;
}
