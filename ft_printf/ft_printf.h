/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcasu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:53:02 by lcasu             #+#    #+#             */
/*   Updated: 2023/04/02 19:26:13 by lcasu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_put_c(char c);
int	ft_put_s(char *s);
int	ft_put_x(unsigned long n);
int	ft_put_up_x(unsigned long n);
int	ft_put_p(unsigned long p);
int	ft_put_d(int n);
int	ft_put_u(unsigned int n);

#endif
