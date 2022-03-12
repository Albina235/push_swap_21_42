#include "../push_swap.h"


void    push_b(t_all *all)
{
    t_one *tmp;

    tmp = all->a->next;
    all->a->prev->next = all->a->next;
    all->a->next->prev = all->a->prev;
    if (all->b)
    {
        all->a->prev = all->b->prev;
        all->a->next = all->b;
        all->b->prev->next = all->a;
        all->b->prev = all->a;
        all->b = all->a;
    }
    else
    {
        all->b = all->a;
        all->a->next = all->b;
        all->a->prev = all->b;
    }
    all->a = tmp;
}

void    push_a(t_all *all)
{
    t_one *tmp;

    tmp = all->b->next;
    all->b->prev->next = all->b->next;
    all->b->next->prev = all->b->prev;
    if (all->a)
    {
        all->b->prev = all->a->prev;
        all->b->next = all->a;
        all->a->prev->next = all->b;
        all->a->prev = all->b;
        all->a = all->b;
    }
    else
    {
        all->a = all->b;
        all->b->next = all->a;
        all->b->prev = all->a;
    }
    all->b = tmp;
}


void    pb(t_all *all, int flag)
{
    if (all->len_a == 0)
        return ;
    push_b(all);
    if (all->len_a == 1)
        all->a = NULL;
    all->len_a--;
    all->len_b++;
    if (flag)
        write (1, "pb\n", 3);
}

void    pa(t_all *all, int flag)
{
    if (all->len_b == 0)
        return ;
    push_a(all);
    if (all->len_b == 1)
        all->b = NULL;
    all->len_a++;
    all->len_b--;
    if (flag)
        write (1, "pa\n", 3);
}