/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:52:33 by laburomm          #+#    #+#             */
/*   Updated: 2024/09/25 09:13:12 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_sp_handle(char c, va_list argptr)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(argptr, int));
	if (c == 'c')
		count += ft_putchar(va_arg(argptr, int));
	if (c == 's')
		count += ft_putstr(va_arg(argptr, char *));
	if (c == 'x')
		count += ft_puthex(va_arg(argptr, unsigned int), 0);
	if (c == 'X')
		count += ft_puthex(va_arg(argptr, unsigned int), 1);
	if (c == 'u')
		count += ft_putunsigned(va_arg(argptr, unsigned int));
	if (c == 'p')
		count += ft_putptr(va_arg(argptr, unsigned long));
	if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *fixedstring, ...)
{
	va_list	argptr;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(argptr, fixedstring);
	while (fixedstring[i])
	{
		if (fixedstring[i] == '%' && fixedstring[i + 1])
		{
			i++;
			counter += ft_sp_handle(fixedstring[i], argptr);
		}
		else
		{
			ft_putchar(fixedstring[i]);
			counter++;
		}
		i++;
	}
	va_end(argptr);
	return (counter);
}
