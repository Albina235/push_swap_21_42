/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:51:30 by evalorie          #+#    #+#             */
/*   Updated: 2022/03/19 12:51:31 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_to_stack(t_all *all, char **arr)
{
	int	*original;
	int	*sorted;
	int	i;
	int	nb;

	original = malloc(sizeof(int) * all->len_a);
	sorted = malloc(sizeof(int) * all->len_a);
	i = 0;
	while (i < all->len_a)
	{
		nb = ft_atoi(arr[i]);
		original[i] = nb;
		sorted[i] = nb;
		i++;
	}
	bouble_sort(all, sorted, original, all->len_a);
}

void	create_stack(t_all *all, int *sort, int *org, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = 0;
		while (j < len)
		{
			if (org[i] == sort[j])
			{
				lstadd_back(&all->a, new_list(org[i], j + 1));
				break ;
			}
			j++;
		}
	}
	free(org);
	free(sort);
}

t_one	*new_list(int nb, int index)
{
	t_one	*lst;

	lst = malloc(sizeof(t_one));
	if (lst == NULL)
		return (NULL);
	lst->num = nb;
	lst->flag = 0;
	lst->index = index;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

void	lstadd_back(t_one **a, t_one *new)
{
	t_one	*beg;

	if (new == NULL)
		return ;
	beg = *a;
	if (beg)
	{
		if (beg->prev)
		{
			beg->prev->next = new;
			new->prev = beg->prev;
			new->next = beg;
			beg->prev = new;
		}
		else
		{
			beg->prev = new;
			beg->next = new;
			new->prev = beg;
			new->next = beg;
		}
	}
	else
		*a = new;
	return ;
}
