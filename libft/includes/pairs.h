/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pairs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:12:06 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 19:32:30 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIRS_H
# define PAIRS_H
# include <strings.h>
# include "header.h"

t_pair g_pairs[15] =
{
	{ .key = 'd', .f = &p_integer},
	{ .key = 'p', .f = &p_ptr},
	{ .key = 'X', .f = &p_hexa},
	{ .key = 'x', .f = &p_hexa},
	{ .key = 'o', .f = &p_octal},
	{ .key = 'u', .f = &p_unsigned},
	{ .key = 'i', .f = &p_integer},
	{ .key = 'c', .f = &p_char},
	{ .key = 's', .f = &p_string},
	{ .key = '%', .f = &p_percent},
	{ .key = '@', .f = NULL}
};
#endif
