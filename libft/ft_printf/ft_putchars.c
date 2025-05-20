/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:36:33 by lucasu            #+#    #+#             */
/*   Updated: 2025/01/17 11:39:17 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr(char *s)
{
	int		i;
	int		res;

	if (!s)
	{
		res = write(1, "(null)", 6);
		return (res);
	}
	i = 0;
	while (s[i])
		i++;
	res = write(1, s, i);
	return (res);
}
