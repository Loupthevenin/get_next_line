/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:30:34 by ltheveni          #+#    #+#             */
/*   Updated: 2024/11/15 19:27:41 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_read(int fd, char *buf)
{
	ssize_t	nb_read;
	int		is_end_file;
	char	*buffer;

	is_end_file = 0;
	while (!is_end_file)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
		{
			return (NULL);
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	buf = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read(fd, buf);
	if (!buf)
		return (NULL);
	return (buf);
}
