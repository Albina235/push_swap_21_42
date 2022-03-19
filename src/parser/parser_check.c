/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:51:38 by evalorie          #+#    #+#             */
/*   Updated: 2022/03/19 12:51:40 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_argv(char **arr)
{
	int				i;
	int				j;
	long long int	nb;

	i = -1;
	while (arr[++i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][0] == '-' && j == 0)
				j++;
			if (!ft_isdigit(arr[i][j]))
				free_array(arr, -1);
			j++;
		}
		nb = ft_atoi(arr[i]);
		if (nb > MAX_INT || nb < MIN_INT)
			free_array(arr, -1);
	}
}

void	check_repeat(char **arr)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (arr[++i])
	{
		tmp = ft_atoi(arr[i]);
		j = i + 1;
		while (arr[j])
		{
			if (tmp == ft_atoi(arr[j]))
				free_array(arr, -1);
			j++;
		}
	}
}
