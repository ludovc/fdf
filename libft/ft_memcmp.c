/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:57:05 by lucasu            #+#    #+#             */
/*   Updated: 2024/12/03 16:57:37 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*mem1;
	unsigned char	*mem2;

	mem1 = (unsigned char *)s1;
	mem2 = (unsigned char *)s2;
	i = 0;
	while (i < n && mem1[i] == mem2[i])
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return (mem1[i] - mem2[i]);
}
