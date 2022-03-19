/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:48:53 by evalorie          #+#    #+#             */
/*   Updated: 2022/03/19 12:48:55 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_all *all, int flag)
{
	if (all->len_a > 1)
		all->a = all->a->prev;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_all *all, int flag)
{
	if (all->len_b > 1)
		all->b = all->b->prev;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_all *all, int flag)
{
	if (all->len_a > 1 && all->len_b > 1)
	{
		rra(all, 0);
		rrb(all, 0);
		if (flag)
			write(1, "rrr\n", 4);
	}
}
