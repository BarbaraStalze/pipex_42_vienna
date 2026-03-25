/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:58:03 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/28 15:39:40 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	byte;

	str = (unsigned char *) s;
	byte = (unsigned char) c;
	while (n > 0)
	{
		*str = byte;
		str++;
		n--;
	}
	return (s);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char pointer1[] = "Bundesausbildungsforderungsgesetz";
	printf("MF: Before: %s\n", pointer1);
	char *newstring = ft_memset(pointer1, 4, 2);
	printf("MF: After: %s\n", newstring);

	char pointer2[] = "Bundesausbildungsforderungsgesetz";
	printf("OF: Before: %s\n", pointer2);
	newstring = memset(pointer2, 4, 2);
	printf("OF: After: %s\n", newstring);
}
*/
