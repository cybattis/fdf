/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:12:20 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:19:37 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include <limits.h>

static char	*read_buffer(int fd, char *line, char *buffer);
static char	*copy_buffer(char *line, char *buffer, size_t i);
static char	*check_buffer(int fd, char *buffer, char *line);

char	*ft_get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = 0;
	return (read_buffer(fd, line, buffer[fd]));
}

static char	*read_buffer(int fd, char *line, char *buffer)
{
	ssize_t	bytes;

	bytes = 0;
	if (ft_strlen(buffer) == 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(line);
			return (NULL);
		}
		if (bytes == 0 && line[0] == 0)
		{
			free(line);
			return (NULL);
		}
		else if (bytes == 0)
			return (line);
		buffer[bytes] = 0;
	}
	return (check_buffer(fd, buffer, line));
}

static char	*check_buffer(int fd, char *buffer, char *line)
{
	ssize_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (copy_buffer(line, buffer, i + 1));
		i++;
	}
	line = copy_buffer(line, buffer, i);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	return (read_buffer(fd, line, buffer));
}

static char	*copy_buffer(char *line, char *buffer, size_t i)
{
	char	*new_line;
	size_t	line_size;
	size_t	buff_size;

	buff_size = ft_strlen(buffer);
	line_size = ft_strlen(line);
	new_line = (char *)malloc(sizeof(char) * (line_size + i + 1));
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	new_line = ft_memmove(new_line, line, line_size);
	new_line[line_size] = 0;
	ft_strlcat(new_line, buffer, line_size + i + 1);
	ft_memmove(buffer, &buffer[i], buff_size - i);
	buffer[buff_size - i] = 0;
	free(line);
	return (new_line);
}
