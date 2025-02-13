/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:20:37 by laburomm          #+#    #+#             */
/*   Updated: 2025/02/13 08:40:42 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	parse_integer(const char **str)
{
	double	result;

	result = 0.0;
	while (**str >= '0' && **str <= '9')
		result = result * 10.0 + (*(*str)++ - '0');
	return (result);
}

static double	parse_fraction(const char **str)
{
	double	fraction;

	fraction = 1.0;
	while (**str >= '0' && **str <= '9')
	{
		fraction *= 0.1;
		fraction += (*(*str)++ - '0') * fraction;
	}
	return (fraction);
}

static void	checkinput(const char *str)
{
	int i = 0;
	while(str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == '.' )
			i++;
		else
			{
				ft_printf("Invalid arguments\n");
				exit(1);
			}
	}
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;

	result = 0.0;
	fraction = 1.0;
	sign = 1;
	checkinput(str);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = parse_integer(&str);
	if (*str == '.')
	{
		str++;
		fraction = parse_fraction(&str);
	}
	return (result * sign + fraction);
}
