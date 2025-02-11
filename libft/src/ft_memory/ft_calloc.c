/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:34:10 by laburomm          #+#    #+#             */
/*   Updated: 2024/08/29 19:06:16 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>
#include<stdlib.h>
#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t nb);

void	*ft_calloc(size_t nmel, size_t size)
{
	size_t	totalsize;
	void	*ptr;

	totalsize = nmel * size;
	ptr = malloc(totalsize);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, totalsize);
	return (ptr);
}
