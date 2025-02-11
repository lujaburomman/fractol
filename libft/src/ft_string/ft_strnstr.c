/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:37:57 by laburomm          #+#    #+#             */
/*   Updated: 2024/08/29 11:48:43 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t length)
{
	size_t	b;
	size_t	l;

	b = 0;
	l = 0;
	if (little[l] == '\0')
		return ((char *)big);
	while (big[b] != '\0' && b < length)
	{
		if (big[b] == little[0])
		{
			l = 0;
			while (little[l] != '\0'
				&& ((b + l) < length)
				&& big[b + l] == little[l])
			{
				l++;
			}
			if (little[l] == '\0')
				return ((char *)(big + b));
		}
		b++;
	}
	return (NULL);
}
