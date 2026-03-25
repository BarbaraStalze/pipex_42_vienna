/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:40:00 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/24 14:42:08 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	find;
	size_t			strlen;

	strlen = ft_strlen(s);
	find = (unsigned char) c;
	while (strlen + 1 > 0)
	{
		if (*s == find)
			return ((char *)s);
		s++;
		strlen--;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	const char original[] = "Livin-la-vida-loca";
	const char original2[] = "";
	int find1 = 105;
	int find2 = 117;
	int find3 = 0;

	printf("i found at adress: %p %p\n", ft_strchr(original, find1), 
		strchr(original, find1));
	printf("u found at adress: %p %p\n", ft_strchr(original, find2), 
		strchr(original, find2));
	printf("1 found at adress: %p %p\n", ft_strchr(original, find3), 
		strchr(original, find3));

	printf("i found at adress (e. string): %p %p\n", 
		ft_strchr(original2, find1), strchr(original2, find1));
}
*/
