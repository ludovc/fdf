/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcasu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:53:37 by lcasu             #+#    #+#             */
/*   Updated: 2023/04/02 18:57:52 by lcasu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printformatted(char type, va_list ap)
{
	int		len;

	len = 0;
	if (type == 'c')
		len += ft_put_c(va_arg(ap, int));
	else if (type == 's')
		len += ft_put_s(va_arg(ap, char *));
	else if (type == 'p')
		len += ft_put_p(va_arg(ap, unsigned long));
	else if (type == 'd' || type == 'i')
		len += ft_put_d(va_arg(ap, int));
	else if (type == 'u')
		len += ft_put_u(va_arg(ap, unsigned int));
	else if (type == 'x')
		len += ft_put_x(va_arg(ap, unsigned int));
	else if (type == 'X')
		len += ft_put_up_x(va_arg(ap, unsigned int));
	else if (type == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_printformatted(format[i + 1], ap);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}
