/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_name_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 02:08:15 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/01 20:38:57 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char			comment_or_empty(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && (str[i] != COMMENT_CHAR && str[i] != ';'))
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
	while (*str && *str != '"')
		str++;
	str++;
	while (*str && *str != '"')
	{
		str++;
		i++;
		if (i > PROG_NAME_LENGTH)
			return (0);
	}
	if (!*str)
		return (0);
	str++;
	while (*str)
	{
		if (*str == COMMENT_CHAR)
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
	while (*str && *str != '"')
		str++;
	str++;
	while (*str && *str != '"')
	{
		str++;
		i++;
		if (i > COMMENT_LENGTH)
			return (0);
	}
	if (!*str)
		return (0);
	str++;
	while (*str)
	{
		if (*str == COMMENT_CHAR)
			return (1);
		if (*str > 32)
			return (0);
		str++;
	}
	return (1);
}

static char		pars_name_comment_next(t_env *env, const char *str, int i)
{
	if (!ft_strncmp(NAME_CMD_STRING, &str[i], ft_strlen(NAME_CMD_STRING)))
	{
		if (!check_name(str))
		{
			ft_printf("\"%s\" : Badly formatted name\n", env->file_name);
			return (0);
		}
		env->name = 1;
	}
	if (!ft_strncmp(COMMENT_CMD_STRING, &str[i], ft_strlen(NAME_CMD_STRING)))
	{
		if (!check_comment(str))
		{
			ft_printf("\"%s\" : Badly formatted comment\n", env->file_name);
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
		ft_printf("\"%s\" : No name or comment found\n", env->file_name);
		return (0);
	}
	if (!pars_name_comment_next(env, str, i))
		return (0);
	return (1);
}
