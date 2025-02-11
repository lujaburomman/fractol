/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:00:29 by laburomm          #+#    #+#             */
/*   Updated: 2024/10/28 16:37:23 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	s;

	s = 0;
	if (!str)
		return (0);
	if (!c)
		return ((char *)s);
	while (str[s] != '\0')
	{
		if (str[s] == (char)c)
			return ((char *)(str + s));
		s++;
	}
	if (str[s] == (char)c)
		return ((char *)(str + s));
	return (NULL);
}

char	*ft_strjoin(char *t, char *b)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!t)
	{
		t = (char *)malloc(1);
		t[0] = '\0';
	}
	if (!t || !b)
		return (free(t), NULL);
	new_str = malloc(ft_strlen(t) + ft_strlen(b) + 1);
	if (!new_str)
		return (free(t), NULL);
	i = -1;
	j = 0;
	while (t[++i])
		new_str[i] = t[i];
	while (b[j] != '\0')
		new_str[i++] = b[j++];
	new_str[i] = '\0';
	free(t);
	return (new_str);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	if (!str)
		return (0);
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
