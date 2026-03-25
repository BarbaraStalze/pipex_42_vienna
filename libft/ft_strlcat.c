/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:49:28 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/28 16:05:58 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (destlen >= size)
		return (size + srclen);
	else
	{
		i = 0;
		while (src[i] != 0 && destlen + i < size -1)
		{
			dst[destlen + i] = src[i];
			i++;
		}
		if (destlen + i < size)
			dst[destlen + i] = 0;
		return (destlen + srclen);
	}
}

/*
#include <stdio.h>
#include <bsd/string.h>

int main(void)
{
	char begin1[40] = "Hi my name is ";
	const char* add1 = "";

	printf ("%s\n%zu\n", begin1, ft_strlcat(begin1, add1, 30));
	printf ("%s\n%zu\n\n", begin1, ft_strlcat(begin1, add1, 10));

	char begin2[40] = "Hi my name is ";
	const char* add2 = "";

	printf ("%s\n%zu\n", begin2, strlcat(begin2, add2, 30));
	printf ("%s\n%zu\n", begin2, strlcat(begin2, add2, 10));
}
*/
