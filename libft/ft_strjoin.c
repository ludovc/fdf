/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:30:40 by lucasu            #+#    #+#             */
/*   Updated: 2024/12/03 17:09:10 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*res;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	res = malloc(sizeof(char) * lens1 + lens2 + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, lens1);
	ft_memcpy(&res[lens1], s2, lens2);
	res[lens1 + lens2] = '\0';
	return (res);
}
