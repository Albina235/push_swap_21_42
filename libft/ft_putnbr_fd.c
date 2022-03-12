/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:53:49 by evalorie          #+#    #+#             */
/*   Updated: 2021/10/21 18:22:30 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	temp;

	if (n < 0)
		write (fd, "-", 1);
	temp = n / 10;
	if (temp < 0)
		ft_putnbr_fd(-temp, fd);
	if (temp > 0)
		ft_putnbr_fd(temp, fd);
	i = n % 10;
	if (i < 0)
		i = -i;
	i = i + '0';
	write (fd, &i, 1);
}
