#include "push_swap.h"

void	push_down(t_all *all)
{
	all->a->flag = -1;
	ra(all, 1);
}

void	sort_b_three(t_all *all)
{
	int m;
	int n;
	int p;

	if (all->len_b == 0)
		return ;
	m = all->b->index;
	n = all->b->next->index;
	p = all->b->prev->index;
	if (n > m && n > p)
		rrb(all, 1);
	else if (m > n && m > p)
		rb(all, 1);
	m = all->b->index;
	n = all->b->next->index;
	if (m > n)
		sb(all, 1);
}

void	after_math_sorting_three(t_all *all, int flag)
{
	sort_b_three(all);
	if (all->a->index > all->a->next->index && \
		all->a->flag == all->a->next->flag)
		sa(all, 1);
	while (all->len_b != 0)
	{
		if (all->a->index > all->b->index || \
			all->a->flag == -1)
		{
			pa(all, 1);
			push_down(all);
		}
		else
			push_down(all);
	}
	while (all->a->flag == flag && flag != -1 && \
		all->a->index + 1 == all->a->prev->index)
		push_down(all);
}

void	sort_b_five(t_all *all)
{
	int flag;
	int min;
	int i;

	i = all->len_b;
	flag = all->a->flag;
	min = all->a->prev->index + 1;
	while (i > 3)
	{
		if (all->b->index == min)
		{
			pa(all, 2);
			push_down(all);
			min++;
		}
		else
			pa(all, 1);
		i--;
	}
	after_math_sorting_three(all,flag);
}
