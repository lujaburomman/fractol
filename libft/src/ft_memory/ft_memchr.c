/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:52:53 by laburomm          #+#    #+#             */
/*   Updated: 2024/08/29 17:15:06 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>

void	*ft_memchr(const void *s, int c, size_t nb)
{
	const unsigned char	*ptr;

	ptr = s;
	while (nb > 0)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)(ptr));
		ptr++;
		nb--;
	}
	return (NULL);
}
