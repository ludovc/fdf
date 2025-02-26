/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcasu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:53:05 by lcasu             #+#    #+#             */
/*   Updated: 2023/04/02 19:00:13 by lcasu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_put_s(char *s)
{
	int		len;

	len = 0;
	if (!s)
		len = write(1, "(null)", 6);
	else
	{
		while (s[len])
			len += write(1, &s[len], 1);
	}
	return (len);
}
