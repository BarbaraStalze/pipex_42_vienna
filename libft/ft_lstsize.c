/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:01:11 by bastalze          #+#    #+#             */
/*   Updated: 2026/01/20 17:42:56 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*currentnode;

	counter = 0;
	currentnode = lst;
	while (currentnode != NULL)
	{
		currentnode = currentnode->next;
		counter++;
	}
	return (counter);
}
