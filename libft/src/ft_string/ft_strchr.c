/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:54:39 by laburomm          #+#    #+#             */
/*   Updated: 2024/08/29 12:14:23 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>

char	*ft_strchr(const char *str, int c)
{
	size_t	s;

	s = 0;
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
