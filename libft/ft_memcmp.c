/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:55:03 by evalorie          #+#    #+#             */
/*   Updated: 2021/10/21 18:20:26 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char *) s1;
	s4 = (unsigned char *) s2;
	i = 0;
	while (i < n && s3[i] == s4[i])
		i++;
	if (i == n)
		return (0);
	return (s3[i] - s4[i]);
}
/*int main (void)
{
	char	s1[20] = "ABCD";
	char	s2[20] = "abcd";
	const void *s3;
	const void *s4;

	s3 = (const void *)s1;
	s4 = (const void *)s2;
	size_t n = 2;
	printf("%d\n", ft_memcmp(s1, s2, n));
	printf("%d", memcmp(s1, s2, n));
}*/
