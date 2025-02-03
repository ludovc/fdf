/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:12:07 by lucasu            #+#    #+#             */
/*   Updated: 2024/12/03 16:12:36 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = 0;
	i = 0;
	j = 0;
	if (little[0] == '\0')
		res = (char *)big;
	else
	{
		while (big[i] && little[j] != '\0' && (i + j) < len)
		{
			if (big[i + j] == little[j])
				j++;
			else
			{
				j = 0;
				i++;
			}
		}
		if (little[j] == '\0')
			res = (char *)&big[i];
	}
	return (res);
}
