/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:14:36 by laburomm          #+#    #+#             */
/*   Updated: 2024/08/29 12:31:40 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i] == (char)c)
		return ((char *)str + i);
	while (i--)
	{
		if (str[i] == (char)c)
		{
			return ((char *)str + i);
		}
	}
	return (NULL);
}
