/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:43:14 by lucasu            #+#    #+#             */
/*   Updated: 2025/05/12 16:43:15 by lucasu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nxt;

	while ((*lst)->next)
	{
		nxt = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = nxt;
	}
	ft_lstdelone(*lst, (*del));
	*lst = NULL;
}
