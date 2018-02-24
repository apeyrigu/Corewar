/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 22:59:54 by pcluchet          #+#    #+#             */
/*   Updated: 2018/02/24 03:51:22 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	decode_ld(t_vm *vm, t_process *process)
{
	int prs[4];

	if (process->cycles_to_go == 0)
	{
		process->offset = 0;
		if (acquire_params(vm, process, 2, prs))
		{
			do_ld(vm, prs, process);
		}
		process->pc_index += process->offset + 2;
		process->cycles_to_go = -1;
		set_cycles_to_go(vm, process);
	}
	else
		process->cycles_to_go--;
}

void	do_xor(t_vm *vm, int *params, t_process *process)
{
	int result;

	result = params[1] ^ params[2];
	if (params[3] > 0 && params[3] < REG_NUMBER + 1)
	{
		check_debug(vm, process->process_id, 8, params);
		write_reg(process, result, params[3]);
	}
	process->carry = !result;
}
