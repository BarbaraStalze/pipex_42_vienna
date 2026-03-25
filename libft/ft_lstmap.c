/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:52:16 by bastalze          #+#    #+#             */
/*   Updated: 2026/01/20 17:37:43 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_freee(void *result, t_list *head, void (*del)(void *))
{
	free(result);
	ft_lstclear(&head, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*newlst;
	void	*result;

	if (!lst || !f)
		return (NULL);
	result = f(lst->content);
	head = ft_lstnew(result);
	if (!head)
		ft_freee(result, head, del);
	newlst = head;
	lst = lst->next;
	while (lst != 0)
	{
		result = f(lst->content);
		newlst->next = ft_lstnew(result);
		if (!newlst->next)
			return (ft_freee(result, head, del), NULL);
		lst = lst->next;
		newlst = newlst->next;
	}
	return (head);
}
