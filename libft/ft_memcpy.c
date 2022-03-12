/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:38:39 by evalorie          #+#    #+#             */
/*   Updated: 2021/10/13 17:17:56 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*b;

	a = (char *)src;
	b = (char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		b[n - 1] = a[n - 1];
		n--;
	}
	return (dst);
}
