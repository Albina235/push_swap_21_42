/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:10:58 by evalorie          #+#    #+#             */
/*   Updated: 2022/03/19 13:10:59 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_all *all)
{
	int	m;
	int	p;
	int	n;

	m = all->a->index;
	n = all->a->next->index;
	p = all->a->prev->index;
	if (n > m && n > p)
		rra(all, 1);
	else if (m > n && m > p)
		ra(all, 1);
	m = all->a->index;
	n = all->a->next->index;
	if (m > n)
		sa(all, 1);
}

int	short_path(t_all *all)
{
	int		i;
	int		j;
	t_one	*tmp;

	i = 0;
	tmp = all->a;
	while (++i)
	{
		if (tmp->index == all->min_i)
			break ;
		tmp = tmp->next;
	}
	tmp = all->a;
	j = 0;
	while (++j)
	{
		if (tmp->index == all->min_i)
			break ;
		tmp = tmp->prev;
	}
	if (j >= i)
		return (1);
	return (0);
}

void	sort_five(t_all *all)
{
	while (all->len_a > 3)
	{
		median_a(all);
		if (all->a->index == all->min_i)
		{
			pb(all, 1);
			continue ;
		}
		if (short_path(all))
			ra(all, 1);
		else
			rra(all, 1);
	}
	sort_three_a(all);
	pa(all, 1);
	pa(all, 1);
}
