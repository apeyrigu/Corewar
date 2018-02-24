/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 22:37:56 by pcluchet          #+#    #+#             */
/*   Updated: 2018/02/24 03:49:29 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	do_sti(t_vm *vm, t_process *process, int *params)
{
	short			adr;
	int				playerid;
	int				i;
	unsigned char	to_write;

	adr = ((short)params[2] + (short)params[3]);
	check_debug(vm, process->process_id, 12, params);
	playerid = process->num_player;
	i = 0;
	while (i < 4)
	{
		to_write = get_bytes_n(i + 1, params[1]);
		single_access(vm, PCID + adr + i, to_write, playerid);
		i++;
	}
}

void	decode2_sti(t_vm *vm, t_process *process)
{
	int	params[4];

	process->offset = 0;
	if (acquire_params(vm, process, 11, params))
		do_sti(vm, process, params);
	process->pc_index += process->offset + 2;
	process->cycles_to_go = -1;
	set_cycles_to_go(vm, process);
}

void	decode_sti(t_vm *vm, t_process *process)
{
	if (process->cycles_to_go == 0)
		decode2_sti(vm, process);
	else
		process->cycles_to_go--;
}

void	do_and(t_vm *vm, int *params, t_process *process, int totaloffset)
{
	int result;

	totaloffset++;
	result = params[1] & params[2];
	if (params[3] > 0 && params[3] < REG_NUMBER + 1)
	{
		check_debug(vm, process->process_id, 6, params);
		write_reg(process, result, params[3]);
	}
	process->carry = !result;
}
