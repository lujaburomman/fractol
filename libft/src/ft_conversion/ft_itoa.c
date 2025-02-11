/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:00:45 by laburomm          #+#    #+#             */
/*   Updated: 2024/09/15 10:27:50 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*allocate_res(int len)
{
	char	*res;

	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	int		len;
	int		sign;

	num = n;
	len = ft_len(n);
	sign = 1;
	if (num < 0)
	{
		sign = -1;
		num = -num;
	}
	res = allocate_res(len);
	if (!res)
		return (NULL);
	while (len > 0)
	{
		res[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}
