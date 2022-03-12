/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:50:41 by evalorie          #+#    #+#             */
/*   Updated: 2021/10/21 18:17:17 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newelem;

	if (lst == NULL)
		return (NULL);
	newlist = (t_list *)0;
	while (lst)
	{
		newelem = ft_lstnew((*f)(lst->content));
		if (newelem == NULL)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&newlist, newelem);
	}
	return (newlist);
}
