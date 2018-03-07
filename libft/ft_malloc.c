/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 22:18:18 by pcluchet          #+#    #+#             */
/*   Updated: 2018/03/07 23:01:44 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_malloc(size_t size)
{
	void *ret;

	ret = malloc(size);
	if (ret)
		return (ret);
	else
		ft_printf("Allocation failed, aborting.\n");
	exit(-1);
}
