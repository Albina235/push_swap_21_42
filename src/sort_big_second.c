/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:10:14 by evalorie          #+#    #+#             */
/*   Updated: 2022/03/19 13:10:15 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_in_a_to_b(t_all *all)
{
	int	min;

	min = all->a->prev->index + 1;
	if (all->b->index == min)
	{
		pa(all, 1);
		push_down(all);
	}
	else if (all->b->next->index == min)
	{
		sb(all, 1);
		pa(all, 1);
		push_down(all);
	}
	else if (all->b->prev->index == min)
	{
		rrb(all, 1);
		pa(all, 1);
		push_down(all);
	}
	else if (all->a->next->index == min)
	{
		sa(all, 1);
		push_down(all);
	}
}

void	send_back(t_all *all)
{
	int	flag;
	int	min;

	flag = all->a->flag;
	while (all->a->flag == flag && flag != -1)
	{
		min = all->a->prev->index + 1;
		if (all->len_b > 1)
			min_in_a_to_b(all);
		if (all->a->index == min)
			push_down(all);
		else
			pb(all, 1);
	}
}
