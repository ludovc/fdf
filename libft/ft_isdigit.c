/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:51:21 by lucasu            #+#    #+#             */
/*   Updated: 2024/11/25 11:57:27 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	int		res;

	res = 0;
	if (c >= '0' && c <= '9')
	{
		res = 1;
	}
	return (res);
}
