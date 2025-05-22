/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:46:32 by lucasu            #+#    #+#             */
/*   Updated: 2025/01/31 14:51:17 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_remove_excess(char *line)
{
	int		i;
	char	*res;

	i = 0;
	while (line[i])
		i++;
	res = malloc(i + 1);
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		res[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	free(line);
	return (res);
}

char	*gnl_get_excess(const char *line)
{
	char	*res;
	char	*tmp;

	tmp = gnl_strchr(line, '\n');
	if (tmp)
	{
		tmp++;
		res = gnl_strdup(tmp);
	}
	else
		res = NULL;
	return (res);
}

char	*gnl_read_line(int fd, char *line)
{
	int			byte_read;
	char		*buff;

	byte_read = BUFFER_SIZE;
	buff = gnl_calloc(BUFFER_SIZE + 1);
	while (!gnl_strchr(buff, '\n') && byte_read == BUFFER_SIZE)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read > 0)
		{
			buff[byte_read] = '\0';
			line = gnl_strjoin_fs1(line, buff);
		}
		else if (byte_read < 0)
		{
			free(line);
			line = NULL;
		}
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*excess[OPEN_MAX];

	if (BUFFER_SIZE < 0)
		return (NULL);
	line = gnl_calloc(1);
	if (excess[fd])
	{
		line = gnl_strjoin_fs1(line, excess[fd]);
		free(excess[fd]);
		excess[fd] = NULL;
	}
	line = gnl_read_line(fd, line);
	if (!line)
		return (NULL);
	excess[fd] = gnl_get_excess(line);
	line = gnl_remove_excess(line);
	if (line[0] == 0)
	{
		free(excess[fd]);
		free(line);
		line = NULL;
	}
	return (line);
}
