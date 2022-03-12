/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:10:15 by evalorie          #+#    #+#             */
/*   Updated: 2021/10/13 16:08:46 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hays, const char *nee, size_t l)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*nee == '\0')
		return ((char *)hays);
	while (hays[i] && i < l)
	{
		if (hays[i] == nee[0])
		{
			j = 0;
			while (i + j < l && nee[j] && hays[i + j] && hays[i + j] == nee[j])
				j++;
			if (nee[j] == '\0')
				return ((char *)(hays + i));
		}
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	const char s1[20] = "ssddffgg";
	const char s2[20] = "";
	size_t n = 6;
	printf("%s\n", ft_strnstr(s1, s2, n));
	printf("%s", strnstr(s1, s2, n));
}*/
