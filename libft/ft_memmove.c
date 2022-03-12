/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:17:45 by evalorie          #+#    #+#             */
/*   Updated: 2021/10/12 15:34:13 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;

	a = (char *)src;
	b = (char *)dst;
	if (src == 0 && dst == 0)
		return (dst);
	if (b < a)
	{
		while (len)
		{
			*b++ = *a++;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			b[len - 1] = a[len - 1];
			len--;
		}
	}
	return (dst);
}
