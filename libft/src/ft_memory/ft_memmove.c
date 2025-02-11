/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:59:50 by laburomm          #+#    #+#             */
/*   Updated: 2024/08/29 15:55:06 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*to;
	const unsigned char	*from;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	to = (unsigned char *)dest;
	from = (const unsigned char *)src;
	if ((to < from || to >= from + n))
	{
		while (n-- > 0)
		{
			*to++ = *from++;
		}
	}
	else
	{
		to += n;
		from += n;
		while (n-- > 0)
			*(--to) = *(--from);
	}
	return (dest);
}
