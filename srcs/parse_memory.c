/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 02:52:40 by pcluchet          #+#    #+#             */
/*   Updated: 2018/02/24 03:33:48 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	handle_indirect(t_vm *vm, t_process *process, int param_size, int *ret)
{
	int offset;

	offset = process->offset;
	*ret = (short)read_n_oct(vm, (PCID + 2 + offset) % MEM_SIZE, param_size);
	if (process->opcode != 3)
	{
		*ret = (short)(*ret);
		if (!process->longread)
			*ret = (*ret) % IDX_MOD;
		*ret = read_n_oct(vm, PCID + (*ret), (process->longread) ? 2 : 4);
	}
}

int		decode_param(t_vm *vm, t_process *process, int ptype, int param_num)
{
	int param_size;
	int ret;
	int offset;

	ret = 0;
	offset = process->offset;
	param_size = n_bytes_in_type(process->opcode, ptype);
	ptype = code_to_t(ptype);
	if (ptype == T_REG)
	{
		ret = read_n_oct(vm, (PCID + 2 + offset) % MEM_SIZE, param_size);
		if (g_op_tab[process->opcode - 1].rwinfo[param_num - 1] == 'R')
			ret = read_reg(process, ret);
	}
	else if (ptype == T_DIR)
		ret = read_n_oct(vm, (PCID + 2 + offset) % MEM_SIZE, param_size);
	else if (ptype == T_IND)
	{
		handle_indirect(vm, process, param_size, &ret);
	}
	if (param_size == 2)
		ret = (short)ret;
	return (ret);
}

char	acquire_params(t_vm *vm, t_process *process, int opcode, int params[])
{
	char	fail;
	char	current_type;
	int		i;
	int		paramdef;

	fail = 0;
	i = 1;
	paramdef = read_n_oct(vm, PCID + 1, 1);
	while (i <= g_op_tab[opcode - 1].nb_args)
	{
		current_type = get_param_type(i, paramdef);
		if (code_to_t(current_type) &&
				((code_to_t(current_type) & g_op_tab[opcode - 1].args[i - 1]) ==
				code_to_t(current_type)) && !fail)
		{
			params[i] = decode_param(vm, process, current_type, i);
		}
		else
			fail = 1;
		process->offset += n_bytes_in_type(opcode, current_type);
		i++;
	}
	return (!fail);
}
