/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:55:31 by evalorie          #+#    #+#             */
/*   Updated: 2022/03/19 12:55:33 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*parser(char **argv)
{
	t_all	*all;
	char	**arr;

	arr = get_line(argv);
	check_argv(arr);
	check_repeat(arr);
	all = init_struct(arr);
	add_to_stack(all, arr);
	free_array(arr, 0);
	return (all);
}

void	sorter(t_all *all)
{
	if (sort_true(all))
		free_stack(all);
	if (all->len_a < 6)
	{
		sort_five(all);
		free_stack(all);
	}
	move_a_to_b_first(all);
	while (!(sort_true(all) && all->len_b == 0))
	{
		if (all->len_b > 0 && all->len_b < 6)
			sort_b_five(all);
		else if (all->len_b >= 6)
			sent_from_b_to_a(all);
		if (all->len_b == 0)
		{
			sort_five_from_a_to_b(all, 0, 0, 0);
			send_back(all);
		}
	}
}

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc > 1)
	{
		all = parser(argv);
		sorter(all);
		free_stack(all);
	}
	return (0);
}
