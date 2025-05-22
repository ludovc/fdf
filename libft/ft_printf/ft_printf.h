/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:27:14 by lucasu            #+#    #+#             */
/*   Updated: 2025/01/17 11:37:29 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	putnbr(int n);
int	putnbr_u(unsigned int n);
int	putnbr_x(unsigned int n, char *hex);
int	putnbr_p(unsigned long n, char *hex);
int	putp(unsigned long n, char *hex);
int	ft_putchar(char c);
int	putstr(char *s);

#endif
