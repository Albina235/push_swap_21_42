/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:27:43 by evalorie          #+#    #+#             */
/*   Updated: 2021/10/21 18:15:25 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_dop(char *s, int len, int n, int i)
{
	while (n > 0)
	{
		s[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	if (i == 0)
		s[0] = '0';
	return (s);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*s;

	len = ft_len(n);
	i = n;
	if (n <= 0)
		len++;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = (char *)malloc(len * sizeof(char) + 1);
	if (s == NULL)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[len] = '\0';
	s = ft_dop(s, len, n, i);
	return (s);
}

/*int main(void)
{
	printf("%s", ft_itoa(-2147483648));
}*/
