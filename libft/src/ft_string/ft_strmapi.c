/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:03:07 by laburomm          #+#    #+#             */
/*   Updated: 2024/09/15 13:48:53 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*resstr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	resstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!resstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		resstr[i] = f(i, s[i]);
		i++;
	}
	resstr[i] = '\0';
	return (resstr);
}
