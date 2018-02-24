/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 01:03:44 by apeyrigu          #+#    #+#             */
/*   Updated: 2018/02/24 03:29:26 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char			int_to_char(unsigned char value)
{
	if (value < 10)
		return ('0' + value);
	else
		return ('a' + value - 10);
}

void			char_to_hex(char *to, unsigned char value)
{
	to[1] = int_to_char(value % 16);
	value /= 16;
	to[0] = int_to_char(value % 16);
	to[2] = '\0';
}

int				code_to_t(int code)
{
	if (code == 3)
		code = 4;
	return (code);
}

int				n_bytes_in_type(int opcode, char type)
{
	type = code_to_t(type);
	if (type == T_REG)
		return (1);
	else if (type == T_IND)
		return (2);
	else if (type == T_DIR)
	{
		return ((g_op_tab[opcode - 1].dir_size) ? 2 : 4);
	}
	return (0);
}

unsigned char	get_param_type(int n, unsigned char value)
{
	unsigned char	ret;

	ret = 0;
	value = value << ((n - 1) * 2);
	value = value >> 6;
	return (value);
}
