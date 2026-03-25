/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:47:35 by bastalze          #+#    #+#             */
/*   Updated: 2026/01/19 16:57:28 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nn;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		nn = (*lst)->next;
		free(*lst);
		*lst = nn;
	}
	*lst = NULL;
}
