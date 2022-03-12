#include "push_swap.h"

void    median_a(t_all *all)
{
    int i;
    int max;
    int min;

    if (all->len_a == 0)
		return ;
    i = -1;
    min = all->a->index;
    max = all->a->index;
    while (++i < all->len_a)
    {
        if (min > all->a->index)
            min = all->a->index;
        if (max < all->a->index)
            max = all->a->index;
        all->a = all->a->next;
    }
    all->min_i = min;
    all->max_i = max;
    all->median = (max + min) / 2;
}

void    median_b(t_all *all)
{
    int i;
    int min;
    int max;

    if (all->len_b == 0)
		return ;
    min = all->b->index;
    max = all->b->index;
    i = -1;
    while (++i < all->len_b)
    {
        if (min > all->b->index)
            min = all->b->index;
        if (max < all->b->index)
            max = all->b->index;
        all->b = all->b->next;
    }
    all->max_i = max;
    all->median = (min + max) / 2;
}

void    move_down_a(t_all *all)
{
    while (all->b->prev->flag == -1)
        rrb(all, 1);
    while (all->b->flag == -1)
    {
        pa(all, 1);
        ra(all, 1);
    }
}

void    move_a_to_b_first(t_all *all)
{
    int i;

    median_a(all);
    i = all->len_a;
    while(i-- > 0)
    {
        if (all->a->index <= all->median)
        {
            pb(all, 1);
            if (all->b->index == all->min_i)
            {
                all->b->flag = -1;
                rb(all, 1);
            }
        }
        else
        {
                if (all->len_b == all->max_i - all->median + 1)
                    break ;
                else
                    ra(all, 1);
        }
    }
    move_down_a(all);
}

int    sort_true(t_all *all)
{
    int i;
    t_one   *beg;

    beg = all->a;
    i = all->len_a - 1;
    while (i-- > 0)
    {
        if (beg->index > beg->next->index)
            return (0);
        beg = beg->next;
    }
    return (1);
}