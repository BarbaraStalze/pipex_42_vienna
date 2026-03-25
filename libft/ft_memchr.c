/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:50:55 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/28 15:37:04 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	find;
	size_t			i;

	str = (unsigned char *) s;
	find = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == find)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	unsigned char original[] = "Livin-la-vida-loca";
	unsigned char find1 = 'L';
	unsigned char find2 = 'v';
	
	printf("%s\n%s\n", (char *)ft_memchr(original, find1, 1), 
		(char *)memchr(original, find1, 1));
	printf("%s\n%s\n", (char *)ft_memchr(original, find2, 3), 
		(char *)memchr(original, find2, 3));

	char s[] = {0, 1, 2 ,3 ,4 ,5};
	printf("%s\n%s\n", (char *)ft_memchr(s, 0, 1),
		(char *)memchr(s, 0, 1));
}
*/
