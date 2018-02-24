/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_name_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 02:08:15 by abassibe          #+#    #+#             */
/*   Updated: 2018/01/25 04:26:45 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char			comment_or_empty(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && (str[i] != '#' && str[i] != ';'))
	{
		if (str[i] > 32)
			return (0);
		i++;
	}
	return (1);
}

static char		check_name(const char *str)
{
	int		i;

	i = 0;
	while (*str != '"')
		str++;
	str++;
	while (*str != '"')
	{
		str++;
		i++;
		if (i > 128)
			return (0);
	}
	str++;
	while (*str)
	{
		if (*str == '#')
			return (1);
		if (*str > 32)
			return (0);
	}
	return (1);
}

static char		check_comment(const char *str)
{
	int		i;

	i = 0;
	while (*str != '"')
		str++;
	str++;
	while (*str != '"')
	{
		str++;
		i++;
		if (i > 2048)
			return (0);
	}
	str++;
	while (*str)
	{
		if (*str == '#')
			return (1);
		if (*str > 32)
			return (0);
	}
	return (1);
}

static char		pars_name_comment_next(t_env *env, const char *str, int i)
{
	if (str[i + 1] == 'n' && str[i + 2] == 'a' && str[i + 3] == 'm' &&
			str[i + 4] == 'e')
	{
		if (!check_name(str))
		{
			write(2, "Badly formatted name\n", 21);
			return (0);
		}
		env->name = 1;
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'o' && str[i + 3] == 'm' &&
			str[i + 4] == 'm' && str[i + 5] == 'e' && str[i + 6] == 'n' &&
			str[i + 7] == 't')
	{
		if (!check_comment(str))
		{
			write(2, "badly formatted comment\n", 24);
			return (0);
		}
		env->comment = 1;
	}
	return (1);
}

char			pars_name_comment(t_env *env, const char *str)
{
	int		i;

	i = 0;
	if (comment_or_empty(str))
		return (1);
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] != '.')
	{
		write(2, "No name or comment found\n", 25);
		return (0);
	}
	if (!pars_name_comment_next(env, str, i))
		return (0);
	return (1);
}
