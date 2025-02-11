/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:57:52 by laburomm          #+#    #+#             */
/*   Updated: 2024/09/15 13:39:02 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len;
	int		i;
	int		n;

	i = 0;
	n = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[n++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new_str[n++] = s2[i++];
	}
	new_str[n] = '\0';
	return (new_str);
}
