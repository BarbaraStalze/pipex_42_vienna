/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:28:05 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/28 16:11:17 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*pointer;

	if (size != 0)
	{
		if (nmemb > SIZE_MAX / size)
			return (0);
	}
	pointer = malloc(nmemb * size);
	if (pointer == 0)
		return (0);
	ft_bzero(pointer, nmemb * size);
	return (pointer);
}
