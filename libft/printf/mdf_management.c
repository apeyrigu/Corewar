/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdf_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 04:21:47 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 04:21:49 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_mdf	*get_mdf(char *str)
{
	t_mdf *ret;

	ret = (t_mdf*)malloc(sizeof(t_mdf));
	ret->h = ft_count_c('h', str, 0);
	ret->l = ft_count_c('l', str, 0);
	ret->j = ft_count_c('j', str, 0);
	ret->z = ft_count_c('z', str, 0);
	ret->sum = (ret->l + ret->j + ret->h + ret->z);
	return (ret);
}
