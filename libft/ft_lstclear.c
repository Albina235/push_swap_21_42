/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:43:26 by evalorie          #+#    #+#             */
/*   Updated: 2021/10/21 18:15:49 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*v;

	temp = *lst;
	if (*lst == NULL)
		return ;
	while (temp)
	{
		v = temp->next;
		ft_lstdelone(temp, del);
		temp = v;
	}
	*lst = NULL;
}
