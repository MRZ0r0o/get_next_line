/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:08:15 by mradwan           #+#    #+#             */
/*   Updated: 2022/09/23 14:18:22 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// this function used for the rest of lines after read the first one
// and store it in the main function with static
// we count the strlen till "\n", free the string when find '\0'
char	*the_rest(char *k)
{
	int		i;
	char	*str;
	int		x;

	i = 0;
	x = 0;
	while (k[i] != '\0' && k[i] != '\n')
		i++;
	if (k[i] == '\0')
	{
		free(k);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(k) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	while (k[i] != '\0')
		str[x++] = k[i++];
	str[x] = '\0';
	free(k);
	return (str);
}

// The n variable stores the value and keeps it because in 
// the main func the char is "static" keeps all the values stored and only adds
// up on the previous values and dont check what read before as
// long it didnt find '\n' in the string.

char	*readk(int fd, char *k)
{
	char	*str;
	int		n;

	n = 1;
	str = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (ft_strchr(k, '\n') == NULL && n != 0)
	{
		n = read(fd, str, BUFFER_SIZE);
		if (n == -1)
		{
			free(str);
			return (NULL);
		}
		str[n] = '\0';
		k = ft_strjoin(k, str);
	}
	free(str);
	return (k);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*k[12288];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	k[fd] = readk(fd, k[fd]);
	if (!k[fd])
		return (NULL);
	line = takel(k[fd]);
	k[fd] = the_rest(k[fd]);
	return (line);
}
