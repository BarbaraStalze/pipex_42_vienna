/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:51:56 by bastalze          #+#    #+#             */
/*   Updated: 2026/01/19 16:59:13 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*currentnode;

	currentnode = lst;
	if (!lst)
		return (0);
	while (currentnode->next != NULL)
		currentnode = currentnode->next;
	return (currentnode);
}
