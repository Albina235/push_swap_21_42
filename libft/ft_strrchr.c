/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:00:08 by evalorie          #+#    #+#             */
/*   Updated: 2021/10/21 18:51:08 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*p;

	i = 0;
	p = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			p = (char *)&s[i];
		i++;
	}
	if (c == '\0')
		p = (char *)&s[i];
	return (p);
}
