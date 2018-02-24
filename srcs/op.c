/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2018/02/24 03:27:02 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

t_op	g_op_tab[17] =
{
	{ "live", 1, {T_DIR, 0, 0, 0}, 1, 10, "alive", 0, 0, {'R', 0, 0, 0}},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0, 0}, 2, 5, "load", 1, 0,
		{'R', 'W', 0, 0}},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, {'R', 'R'}},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, {'R', 'R'}},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0,
		{'R', 'R', 'W'}},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, {'R', 'R', 'W'}},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, {'R', 'R', 'W'}},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, {'R', 'R', 'W'}},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, {'R'}},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, {'R', 'R', 'W'}},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, {'R', 'R', 'R'}},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, {'R'}},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0,
		{'R', 'W'}},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, {'R', 'R', 'W'}},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, {'R'}},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, {'R'}},
	{0, 0, {0}, 0, 0, 0, 0, 0, {0}}
};

void	(*g_ops[18])(t_vm*, t_process*) = {
	NULL,
	decode_live,
	decode_ld,
	decode_st,
	decode_add,
	decode_sub,
	decode_and,
	decode_or,
	decode_xor,
	decode_zjmp,
	decode_ldi,
	decode_sti,
	decode_fork,
	decode_lld,
	decode_lldi,
	decode_lfork,
	decode_aff
};
