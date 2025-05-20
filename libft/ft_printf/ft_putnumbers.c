/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:39:39 by lucasu            #+#    #+#             */
/*   Updated: 2025/01/17 11:39:40 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr(int n)
{
	int		res;

	res = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		res = ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		res += putnbr(n / 10);
	res += ft_putchar((n % 10) + 48);
	return (res);
}

int	putnbr_u(unsigned int n)
{
	int		res;

	res = 0;
	if (n >= 10)
		res += putnbr_u(n / 10);
	res += ft_putchar((n % 10) + 48);
	return (res);
}

int	putnbr_x(unsigned int n, char *hex)
{
	int		res;

	res = 0;
	if (n >= 16)
		res += putnbr_x(n / 16, hex);
	res += ft_putchar((hex[n % 16]));
	return (res);
}

int	putnbr_p(unsigned long n, char *hex)
{
	int		res;

	res = 0;
	if (n >= 16)
		res += putnbr_p(n / 16, hex);
	res += ft_putchar((hex[n % 16]));
	return (res);
}

int	putp(unsigned long n, char *hex)
{
	int		res;

	res = 0;
	if (!n)
	{
		res += write(1, "(nil)", 5);
	}
	else
	{
		res += write(1, "0x", 2);
		res += putnbr_p(n, hex);
	}
	return (res);
}
