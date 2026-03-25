/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:03:34 by bastalze          #+#    #+#             */
/*   Updated: 2025/11/03 11:17:07 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	destination = (unsigned char *) dest;
	source = (unsigned char *) src;
	i = 0;
	while (n > i)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char pointer1[] = "Hallo";
	const char *text1 = "Hui";
	printf("Before: %s\n", pointer1);
	char *newstring1 = ft_memcpy(pointer1, text1, 2);
	printf("After: %s\n\n", newstring1);

	char pointer2[] = "Hallo";
	const char *text2 = "Hui";
	printf("Before: %s\n", pointer2);
	char *newstring2 = memcpy(pointer2, text2, 2);
	printf("After: %s\n\n", newstring2);
}
*/
