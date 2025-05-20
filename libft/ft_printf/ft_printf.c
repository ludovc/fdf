/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:27:11 by lucasu            #+#    #+#             */
/*   Updated: 2025/01/17 11:36:59 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	placeholder(char type, va_list ap)
{
	int		res;

	res = 0;
	if (type == 'c')
		res += ft_putchar(va_arg(ap, int));
	else if (type == 's')
		res += putstr(va_arg(ap, char *));
	else if (type == '%')
		res += ft_putchar('%');
	else if (type == 'd' || type == 'i')
		res += putnbr(va_arg(ap, int));
	else if (type == 'u')
		res += putnbr_u(va_arg(ap, int));
	else if (type == 'x')
		res += putnbr_x(va_arg(ap, int), "0123456789abcdef");
	else if (type == 'X')
		res += putnbr_x(va_arg(ap, int), "0123456789ABCDEF");
	else if (type == 'p')
		res += putp(va_arg(ap, long), "0123456789abcdef");
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		res;

	res = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			res += placeholder(format[i + 1], ap);
			i++;
		}
		else
		{
			res += write(1, &format[i], 1);
		}
		i++;
	}
	return (res);
}
