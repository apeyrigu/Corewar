/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:35:42 by pcluchet          #+#    #+#             */
/*   Updated: 2018/02/24 04:43:36 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*retour;

	if (!lst)
		return (NULL);
	if (lst->next == NULL)
	{
		retour = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		return (retour);
	}
	else
	{
		retour = ft_lstmap(lst->next, f);
		ft_lstadd(&retour, f(lst));
		return (retour);
	}
}
