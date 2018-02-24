/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 22:58:29 by pcluchet          #+#    #+#             */
/*   Updated: 2018/02/24 03:50:00 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	decode_and(t_vm *vm, t_process *process)
{
	int	prs[4];

	if (process->cycles_to_go == 0)
	{
		process->offset = 0;
		if (acquire_params(vm, process, 6, prs))
			do_and(vm, prs, process, process->offset);
		process->pc_index += process->offset + 2;
		process->cycles_to_go = -1;
		set_cycles_to_go(vm, process);
	}
	else
		process->cycles_to_go--;
}

void	decode_zjmp(t_vm *vm, t_process *process)
{
	short		adresse;
	int			params[1];

	if (process->cycles_to_go == 0)
	{
		adresse = read_n_oct(vm, PCID + 1, 2);
		params[0] = (short)adresse;
		if (process->carry == 1)
		{
			check_debug(vm, process->process_id, 9, params);
			PCID = (PCID + (short)adresse) % MEM_SIZE;
			if (PCID < 0)
				PCID = MEM_SIZE + PCID;
		}
		else
		{
			check_debug(vm, process->process_id, 10, params);
			PCID = (PCID + 3) % MEM_SIZE;
		}
		process->cycles_to_go = -1;
		set_cycles_to_go(vm, process);
	}
	else
		process->cycles_to_go--;
}

void	decode_lfork(t_vm *vm, t_process *process)
{
	short		adresse;
	t_process	new_process;
	int			params[1];

	if (process->cycles_to_go == 0)
	{
		adresse = read_n_oct(vm, PCID + 1, 2);
		params[0] = adresse;
		check_debug(vm, process->process_id, 16, params);
		new_process = (t_process){
			.num_player = process->num_player,
				.pc_index = (process->pc_index + (adresse)) % MEM_SIZE,
				.carry = process->carry, .lives = process->lives,
				.next = NULL, .cycles_to_go = -1, .offset = 0,
				.process_id = vm->nbprocess + 1, .order = 0
		};
		copy_regs(process, &new_process);
		set_cycles_to_go(vm, &new_process);
		add_process(vm, new_process);
		PCID = (PCID + 3) % MEM_SIZE;
		process->cycles_to_go = -1;
		set_cycles_to_go(vm, process);
	}
	else
		process->cycles_to_go--;
}

void	decode_fork(t_vm *vm, t_process *process)
{
	short		adresse;
	int			params[1];
	t_process	new_process;

	if (process->cycles_to_go == 0)
	{
		adresse = read_n_oct(vm, PCID + 1, 2);
		params[0] = adresse;
		check_debug(vm, process->process_id, 13, params);
		new_process = (t_process){
			.num_player = process->num_player,
			.pc_index = (process->pc_index + (adresse % IDX_MOD)) % MEM_SIZE,
			.carry = process->carry, .lives = process->lives, .next = NULL,
			.cycles_to_go = -1, .offset = 0, .process_id = vm->nbprocess + 1,
			.order = 0
		};
		copy_regs(process, &new_process);
		set_cycles_to_go(vm, &new_process);
		add_process(vm, new_process);
		PCID = (PCID + 3) % MEM_SIZE;
		process->cycles_to_go = -1;
		set_cycles_to_go(vm, process);
	}
	else
		process->cycles_to_go--;
}
