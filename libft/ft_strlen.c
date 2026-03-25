/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:26:04 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/28 16:08:49 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len ++;
	return (len);
}

/*
#include <string.h>
#include <stdio.h>
int	main (void)
{
	printf("This is the length of my string: %lu\n", 
		ft_strlen ("New day, new possibilities"));
	printf("This is the length of my string: %lu\n", ft_strlen (""));
	printf("This is the length of my string: %lu\n\n", ft_strlen ("567"));
	printf("OF: This is the length of my string: %lu\n", 
		strlen ("New day, new possibilities"));
	printf("OF: This is the length of my string: %lu\n", strlen (""));
	printf("OF: This is the length of my string: %lu\n", strlen ("567"));
}
*/
