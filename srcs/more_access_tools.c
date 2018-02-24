/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_access_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 01:55:59 by pcluchet          #+#    #+#             */
/*   Updated: 2018/02/24 02:48:12 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		add_process(t_vm *vm, t_process to_add)
{
	to_add.next = vm->process;
	vm->process = malloc(sizeof(t_process));
	ft_memcpy(vm->process, &to_add, sizeof(t_process));
	vm->nbprocess++;
}

void		single_access(t_vm *vm, int where, unsigned char what, int who)
{
	if ((where % MEM_SIZE) < 0)
	{
		where = MEM_SIZE + where;
	}
	((unsigned char*)(vm->arena))[where % MEM_SIZE] = what;
	((unsigned char*)(vm->arena_map))[where % MEM_SIZE] = who;
}

t_process	*get_process_for_player(t_vm *vm, int playernum)
{
	t_process *process;

	process = vm->process;
	while (process)
	{
		if (process->num_player == playernum)
			return (process);
		process = process->next;
	}
	return (process);
}
