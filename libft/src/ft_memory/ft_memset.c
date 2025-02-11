/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:11:23 by laburomm          #+#    #+#             */
/*   Updated: 2024/08/29 13:41:17 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>

void	*ft_memset(void *ptr, int value, size_t nb)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (nb > 0)
	{
		*p = (unsigned char)value;
		p++;
		nb--;
	}
	return (ptr);
}
