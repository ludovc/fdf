/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:53:35 by lucasu            #+#    #+#             */
/*   Updated: 2024/11/27 11:38:46 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
	{
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	else
		return (NULL);
}
