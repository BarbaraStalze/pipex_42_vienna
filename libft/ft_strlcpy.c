/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:46:12 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/27 16:28:55 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	i = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (i + 1 < size && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (srclen);
}

/*
#include <stdio.h>
#include <bsd/string.h>
int main(void)
{
	char s1[] = "Eita.porra";
	char d1[10] = "8";
	int r = 0;

	printf("Original string: %s\n", s1);
	r = ft_strlcpy(d1, s1, 5);
	printf("My function after copying: %s\n%d\n", d1, r);

	char s2[] = "Eita.porra";
	char d2[10] = "8";
	r = 0;

	printf("Original string: %s\n", s2);
	r = strlcpy(d2, s2, 5);
	printf("Original function after copying: %s\n%d\n", d2, r);
}
*/
