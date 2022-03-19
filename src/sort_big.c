/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:10:38 by evalorie          #+#    #+#             */
/*   Updated: 2022/03/19 13:10:39 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_in_b_to_a(t_all *all)
{
	int	min;

	min = all->a->prev->index + 1;
	if (all->b->index == min)
	{
		pa(all, 1);
		push_down(all);
		return (1);
	}
	else if (all->a->index == min)
		push_down(all);
	else if (all->a->next->index == min)
	{
		sa(all, 1);
		push_down(all);
	}
	return (0);
}

void	sent_from_b_to_a(t_all *all)
{
	int	i;

	median_b(all);
	i = all->len_b;
	while (i-- != 0)
	{
		if (min_in_b_to_a(all))
			continue ;
		if (all->b->index > all->median)
		{
			all->b->flag++;
			pa(all, 1);
		}
		else
		{
			all->b->flag++;
			rb(all, 1);
		}
	}
}

void	sort_five_from_a_to_b_sec(t_all *all, int f)
{
	sort_b_three(all);
	if (all->a->index > all->a->next->index && \
		all->a->flag == all->a->next->flag)
		sa(all, 1);
	while (all->len_b != 0)
	{
		if (all->a->index > all->b->index || \
			all->a->flag != f)
		{
			pa(all, 1);
			push_down(all);
		}
		else
			push_down(all);
	}
	while (all->a->flag == f && f != -1)
		push_down(all);
}

void	sort_five_from_a_to_b(t_all *all, int i, int f, int min)
{
	t_one	*tmp;

	min = all->a->prev->index + 1;
	f = all->a->flag;
	tmp = all->a;
	while (tmp->flag == f && f != -1)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < 6)
	{
		while (i > 2)
		{
			if (all->a->index == min)
			{
				push_down(all);
				min++;
			}
			else
				pb(all, 1);
			i--;
		}
		sort_five_from_a_to_b_sec(all, f);
	}
}
