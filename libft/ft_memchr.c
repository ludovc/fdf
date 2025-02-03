/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:53:35 by lucasu            #+#    #+#             */
/*   Updated: 2024/12/02 15:54:12 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && ((unsigned char *)s)[i] != (unsigned char)c)
	{
		i++;
	}
	if (i < n && ((unsigned char *)s)[i] == (unsigned char)c)
	{
		return ((void *)&((unsigned char *)s)[i]);
	}
	else
	{
		return (NULL);
	}
}
