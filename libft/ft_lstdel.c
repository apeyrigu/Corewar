/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:41:28 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/15 20:41:40 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next == NULL)
	{
		ft_lstdelone(&(*alst), del);
	}
	else
	{
		ft_lstdel(&(*alst)->next, del);
		ft_lstdelone(&(*alst), del);
	}
}
