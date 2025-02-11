/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:52:58 by laburomm          #+#    #+#             */
/*   Updated: 2024/09/15 13:47:52 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			counter++;
		}
		i++;
	}
	return (counter);
}

static char	*ft_write_word(const char *s, size_t len)
{
	char	*current_word;

	current_word = (char *)malloc(len + 1);
	if (!current_word)
		return (NULL);
	ft_memcpy(current_word, s, len);
	current_word[len] = '\0';
	return (current_word);
}

int	malloc_free(char **result, size_t i)
{
	if (!result[i])
	{
		while (i-- > 0)
			free(result[i]);
		free(result);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	const char	*start;
	int			i;

	result = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = s;
			while (*start && *start != c)
				start++;
			result[i++] = ft_write_word(s, (start - s));
			if (!malloc_free(result, i - 1))
				return (NULL);
			s = start;
		}
	}
	result[i] = '\0';
	return (result);
}
