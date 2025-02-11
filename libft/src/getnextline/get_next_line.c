/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:00:15 by laburomm          #+#    #+#             */
/*   Updated: 2024/10/29 16:24:59 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_buffer_leftover(char *buffer)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	leftover = malloc(ft_strlen(buffer) - i + 1);
	if (!leftover)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		leftover[j++] = buffer[i++];
	leftover[j] = '\0';
	free(buffer);
	return (leftover);
}

char	*ft_readfd(int fd, char *temp_buffer)
{
	char	*buf;
	ssize_t	bytesread;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr(temp_buffer, '\n') && (bytesread != 0))
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread == -1)
		{
			if (temp_buffer)
				free(temp_buffer);
			free(buf);
			return (NULL);
		}
		buf[bytesread] = '\0';
		temp_buffer = ft_strjoin(temp_buffer, buf);
		if (!temp_buffer)
			return (free(buf), NULL);
	}
	free(buf);
	return (temp_buffer);
}

char	*get_next_line(int fd)
{
	static char	*temp_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp_buffer = ft_readfd(fd, temp_buffer);
	if (!temp_buffer)
		return (free(temp_buffer), NULL);
	line = ft_line(temp_buffer);
	if (!line)
		return (free(temp_buffer), temp_buffer = NULL);
	if (!*line)
		return (free(line), free(temp_buffer), temp_buffer = NULL);
	temp_buffer = ft_buffer_leftover(temp_buffer);
	if (temp_buffer && !*temp_buffer)
	{
		free(temp_buffer);
		temp_buffer = NULL;
	}
	return (line);
}
