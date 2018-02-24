/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 01:20:39 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/09 14:16:28 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_lower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

static int	is_upper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int			ft_isalpha(int c)
{
	return (is_upper(c) || is_lower(c));
}
