/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:49:02 by evalorie          #+#    #+#             */
/*   Updated: 2022/03/19 12:49:03 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_all *all, int flag)
{
	int	tmp;

	if (all->len_a < 2)
		return ;
	tmp = all->a->num;
	all->a->num = all->a->next->num;
	all->a->next->num = tmp;
	tmp = all->a->index;
	all->a->index = all->a->next->index;
	all->a->next->index = tmp;
	tmp = all->a->flag;
	all->a->flag = all->a->next->flag;
	all->a->next->flag = tmp;
	if (flag)
		write (1, "sa\n", 3);
}

void	sb(t_all *all, int flag)
{
	int	tmp;

	if (all->len_b < 2)
		return ;
	tmp = all->b->num;
	all->b->num = all->b->next->num;
	all->b->next->num = tmp;
	tmp = all->b->index;
	all->b->index = all->b->next->index;
	all->b->next->index = tmp;
	tmp = all->b->flag;
	all->b->flag = all->b->next->flag;
	all->b->next->flag = tmp;
	if (flag)
		write (1, "sb\n", 3);
}

void	ss(t_all *all, int flag)
{
	if (all->len_a > 1 && all->len_b > 1)
	{
		sa(all, 0);
		sb(all, 0);
		if (flag)
			write(1, "ss\n", 3);
	}
}
