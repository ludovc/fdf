/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcasu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:56:52 by lcasu             #+#    #+#             */
/*   Updated: 2023/04/02 19:19:29 by lcasu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_x(unsigned long n)
{
	int		len;

	len = 0;
	if (n >= 16)
	{
		len += ft_put_x(n / 16);
		len += ft_put_x(n % 16);
	}
	else
	{
		if (n < 10)
			len += ft_put_c(n + 48);
		else
			len += ft_put_c((n - 10) + 'a');
	}
	return (len);
}

int	ft_put_up_x(unsigned long n)
{
	int		len;

	len = 0;
	if (n >= 16)
	{
		len += ft_put_up_x(n / 16);
		len += ft_put_up_x(n % 16);
	}
	else
	{
		if (n < 10)
			len += ft_put_c(n + 48);
		else
			len += ft_put_c((n - 10) + 'A');
	}
	return (len);
}

int	ft_put_p(unsigned long p)
{
	int		len;

	len = 0;
	if (!p)
	{
		len += write(1, "(nil)", 5);
	}
	else
	{
		len += write(1, "0x", 2);
		len += ft_put_x(p);
	}
	return (len);
}

int	ft_put_d(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		len += ft_put_d(n / 10);
	len += ft_put_c(n % 10 + 48);
	return (len);
}

int	ft_put_u(unsigned int n)
{
	int		len;

	len = 0;
	if (n >= 10)
		len += ft_put_d(n / 10);
	len += ft_put_c(n % 10 + 48);
	return (len);
}
