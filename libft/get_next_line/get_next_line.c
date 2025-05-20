/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:22:31 by lucasu            #+#    #+#             */
/*   Updated: 2025/01/31 14:22:32 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remove_excess(char *line)
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

char	*ft_get_excess(const char *line)
{
	char	*res;
	char	*tmp;

	tmp = ft_strchr(line, '\n');
	if (tmp)
	{
		tmp++;
		res = ft_strdup(tmp);
	}
	else
		res = NULL;
	return (res);
}

char	*ft_read_line(int fd, char *line)
{
	int			byte_read;
	char		*buff;

	byte_read = BUFFER_SIZE;
	buff = ft_calloc(BUFFER_SIZE + 1);
	while (!ft_strchr(buff, '\n') && byte_read == BUFFER_SIZE)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read > 0)
		{
			buff[byte_read] = '\0';
			line = ft_strjoin_fs1(line, buff);
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
	static char	*excess = 0;

	if (BUFFER_SIZE < 0)
		return (NULL);
	line = ft_calloc(1);
	if (excess)
	{
		line = ft_strjoin_fs1(line, excess);
		free(excess);
		excess = NULL;
	}
	line = ft_read_line(fd, line);
	if (!line)
		return (NULL);
	excess = ft_get_excess(line);
	line = ft_remove_excess(line);
	if (line[0] == 0)
	{
		free(excess);
		free(line);
		line = NULL;
	}
	return (line);
}
