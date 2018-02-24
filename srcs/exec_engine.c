/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 05:53:47 by apeyrigu          #+#    #+#             */
/*   Updated: 2018/02/24 05:24:19 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	exec_process(t_vm *vm, t_process *process, int order)
{
	if (PCID < 0)
	{
		PCID = (MEM_SIZE + (PCID % MEM_SIZE));
		process->cycles_to_go = -1;
		set_cycles_to_go(vm, process);
	}
	if (ARENA[PCID] > 0 && ARENA[PCID] < 17)
	{
		if (process->cycles_to_go == 0)
		{
			process->longread = 0;
			process->order = order;
			process->pc_index = process->pc_index % MEM_SIZE;
			(g_ops[ARENA[PCID]])(vm, process);
		}
		else
			process->cycles_to_go--;
	}
	else
	{
		process->pc_index = (process->pc_index + 1) % MEM_SIZE;
		set_cycles_to_go(vm, process);
	}
}

void	exec_process_list(t_vm *vm, t_process *process)
{
	t_process		*current_process;
	int				order;

	order = 0;
	current_process = process;
	while (current_process)
	{
		exec_process(vm, current_process, order);
		current_process = current_process->next;
		order++;
	}
}

void	play(t_vm *vm)
{
	exec_process_list(vm, vm->process);
}

void	kill_process(t_vm *vm, int pid)
{
	t_process			*current_process;
	t_process			*prev_process;
	char				firstone;
	int					i;
	int					temp;

	i = -42;
	firstone = 1;
	current_process = vm->process;
	while (current_process)
	{
		if (current_process->process_id == pid)
		{
			if (firstone)
				vm->process = current_process->next;
			else
				prev_process->next = current_process->next;
			temp = current_process->lastlive;
			check_debug(vm, pid, (vm->cycle - temp) * -1, &i);
			return ;
		}
		prev_process = current_process;
		current_process = current_process->next;
		firstone = 0;
	}
}

int		check_lives_process(t_vm *vm)
{
	t_process			*current_process;
	t_process			*temp;
	int					total_lives;
	char				need_free;

	need_free = 0;
	total_lives = 0;
	current_process = vm->process;
	while (current_process)
	{
		if (current_process->lives == 0 && (need_free = 1) == 1)
			kill_process(vm, current_process->process_id);
		total_lives += current_process->lives;
		current_process->lives = 0;
		temp = current_process;
		current_process = current_process->next;
		if (need_free)
		{
			free(temp);
			need_free = 0;
		}
	}
	return ((total_lives >= NBR_LIVE) ? 1 : 0);
}
