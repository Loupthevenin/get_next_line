/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:30:34 by ltheveni          #+#    #+#             */
/*   Updated: 2024/11/18 09:01:49 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join(char *buf, char *buffer)
{
	char	*buf_temp;

	buf_temp = ft_strjoin(buf, buffer);
	free(buf);
	return (buf_temp);
}

char	*ft_read(int fd, char *buf)
{
	ssize_t	nb_read;
	char	*buffer;

	if (!buf)
		buf = (char *)ft_calloc(1, 1);
	if (!buf)
		return (NULL);
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	nb_read = 1;
	while (nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(buffer);
			free(buf);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		buf = ft_join(buf, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (buf);
}

char	*ft_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next(char *buf)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	next = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	if (!next)
	{
		free(buf);
		return (NULL);
	}
	i++;
	j = 0;
	while (buf[i])
		next[j++] = buf[i++];
	free(buf);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = ft_read(fd, buf[fd]);
	if (!buf[fd])
	{
		free(buf[fd]);
		buf[fd] = NULL;
		return (NULL);
	}
	line = ft_line(buf[fd]);
	buf[fd] = ft_next(buf[fd]);
	return (line);
}
