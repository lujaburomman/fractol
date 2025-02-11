/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:15:25 by laburomm          #+#    #+#             */
/*   Updated: 2024/08/29 18:30:10 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>

int	ft_memcmp(const void *str1, const void *str2, size_t nb)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = str1;
	ptr2 = str2;
	while (nb > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		nb--;
	}
	return (0);
}
