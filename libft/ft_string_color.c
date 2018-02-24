/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:28:27 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/15 20:31:13 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

char	*ft_string_color(char *str, char color)
{
	char *final;
	char *interm;

	if (color == 'R')
		interm = ft_strjoin(RED, str);
	else if (color == 'G')
		interm = ft_strjoin(GRN, str);
	else if (color == 'Y')
		interm = ft_strjoin(YEL, str);
	else if (color == 'B')
		interm = ft_strjoin(BLU, str);
	else if (color == 'M')
		interm = ft_strjoin(MAG, str);
	else if (color == 'C')
		interm = ft_strjoin(CYN, str);
	else if (color == 'W')
		interm = ft_strjoin(WHT, str);
	else
		interm = ft_strjoin(WHT, str);
	final = ft_strjoin(interm, RESET);
	free(interm);
	return (final);
}
