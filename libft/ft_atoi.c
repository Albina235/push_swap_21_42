/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:14:17 by evalorie          #+#    #+#             */
/*   Updated: 2021/10/21 18:04:18 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int	i;
	int				minus;
	int				c;

	i = 0;
	minus = 1;
	c = 0;
	while (str[c] == '\t' || str[c] == '\n' || str[c] == '\r'
		|| str[c] == '\v' || str[c] == '\f' || str[c] == ' ')
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			minus = -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		i = i * 10 + (str[c] - '0');
		c++;
	}
	return (minus * i);
}

/*int	main(void)
{
	printf("%d", ft_atoi(" 	-834 5346"));
}*/
