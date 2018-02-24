/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:34:24 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/15 20:34:27 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_print_color(char *str, char color)
{
	char *to_print;

	to_print = ft_string_color(str, color);
	ft_putstr(to_print);
	free(to_print);
}
