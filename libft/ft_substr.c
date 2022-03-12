/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:29:52 by evalorie          #+#    #+#             */
/*   Updated: 2021/10/21 18:52:21 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((int)ft_strlen((char *)s) - (int)start < (int)len
		&& (int)ft_strlen((char *)s) - (int)start >= 0)
		len = ft_strlen((char *)s) - start;
	else if ((int)ft_strlen((char *)s) - (int)start < 0)
		return (ft_calloc(1, sizeof(char)));
	sub = (char *)malloc((sizeof(char) * len + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

/*int main(void)
{
	const char s[20] = "skfonsknvkmoer55555";
	printf("%s", ft_substr(s, 0, 500));
}*/
