/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:48:29 by evalorie          #+#    #+#             */
/*   Updated: 2022/03/19 12:48:31 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_all *all, int flag)
{
	if (all->len_a > 1)
		all->a = all->a->next;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_all *all, int flag)
{
	if (all->len_b > 1)
		all->b = all->b->next;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_all *all, int flag)
{
	if (all->len_a > 1 && all->len_b > 1)
	{
		ra(all, 0);
		rb(all, 0);
		if (flag)
			write (1, "rr\n", 3);
	}
}
