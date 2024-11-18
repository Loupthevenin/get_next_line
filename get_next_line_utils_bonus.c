/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:32:55 by ltheveni          #+#    #+#             */
/*   Updated: 2024/11/18 08:30:54 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (count != 0 && size > 65535 / count)
		return (NULL);
	result = (void *)malloc(count * size);
	if (!result)
		return (NULL);
	ft_bzero(result, count * size);
	return (result);
}

char	*ft_strchr(char const *s, int c)
{
	char	*result;

	result = (char *)s;
	while (*result && *result != (char)c)
		result++;
	if (!*result && (char)c != '\0')
		return (NULL);
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s_len;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	s_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		result[i] = *s2++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
