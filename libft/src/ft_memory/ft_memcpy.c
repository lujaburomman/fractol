/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:17:57 by laburomm          #+#    #+#             */
/*   Updated: 2024/08/29 15:30:24 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*to;
	const unsigned char	*from;

	to = dest;
	from = src;
	i = 0;
	if (to == NULL && from == NULL)
		return (NULL);
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (dest);
}
