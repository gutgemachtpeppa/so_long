/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalfrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:47:39 by ahalfrun          #+#    #+#             */
/*   Updated: 2021/12/17 22:20:22 by ahalfrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*rem_check(char **rem)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	line = NULL;
	while ((*rem)[i] && (*rem)[i] != '\n')
		i++;
	if ((*rem)[i] == '\n')
	{
		line = ft_substr(*rem, 0, i + 1);
		temp = ft_strdup(*rem + i + 1);
		free(*rem);
		*rem = temp;
		if (!**rem)
		{
			free(*rem);
			*rem = NULL;
		}
		return (line);
	}
	line = ft_strdup(*rem);
	free(*rem);
	*rem = NULL;
	return (line);
}

char	*line_check(char **rem, size_t read_bytes)
{
	if (read_bytes < 0)
		return (NULL);
	if (!read_bytes && (!rem || !*rem))
		return (NULL);
	return (rem_check(rem));
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*rem;
	char		*temp;
	size_t		read_bytes;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) == -1)
		return (NULL);
	read_bytes = read(fd, buff, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		if (!rem)
			rem = ft_strdup("");
		temp = ft_strjoin(rem, buff);
		free(rem);
		rem = temp;
		if (ft_strchr(buff, '\n'))
			break ;
		read_bytes = read(fd, buff, BUFFER_SIZE);
	}
	line = line_check(&rem, read_bytes);
	return (line);
}
