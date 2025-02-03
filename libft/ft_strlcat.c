/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:40:07 by lucasu            #+#    #+#             */
/*   Updated: 2024/12/03 16:52:59 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (s[i] && i < maxlen)
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	l;

	l = ft_strnlen(dest, size);
	if (l == size)
	{
		return (l + ft_strlen(src));
	}
	else
	{
		return (l + ft_strlcpy(dest + l, src, size - l));
	}
}
