/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:33:43 by lucasu            #+#    #+#             */
/*   Updated: 2025/05/12 16:41:57 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_word(char c, char check)
{
	return (!(c == check || c == '\0'));
}

static int	count_words(char const *str, char check)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (str[i])
	{
		while (!is_word(str[i], check) && str[i])
			i++;
		if (is_word(str[i], check))
			res++;
		while (is_word(str[i], check))
			i++;
	}
	return (res);
}

static int	word_len(char const *str, char check)
{
	int		i;

	i = 0;
	while (is_word(str[i], check))
		i++;
	return (i);
}

static char	*dup_word(char const *str, char check)
{
	char	*res;
	int		i;
	int		len;

	len = word_len(str, check);
	res = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		size;
	int		i;
	int		j;

	j = 0;
	size = count_words(s, c);
	res = malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (s[i])
	{
		while (!is_word(s[i], c) && s[i])
			i++;
		if (is_word(s[i], c))
		{
			res[j] = dup_word(&s[i], c);
			j++;
		}
		while (is_word(s[i], c))
			i++;
	}
	res[j] = NULL;
	return (res);
}
