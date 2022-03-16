/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:37:45 by evalorie          #+#    #+#             */
/*   Updated: 2021/11/24 15:39:23 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		i;
	char	buff;

	i = 0;
	line = malloc(sizeof(char) * 6);
	while (read(fd, &buff, 1) > 0)
	{
		if (i == 5)
			break ;
		if (buff == '\n')
		{
			line[i] = '\0';
			break ;
		}
		line[i] = buff;
		i++;
	}
	line[i] = '\0';
	if (line[0] == '\0')
		return (NULL);
	return (line);
}
