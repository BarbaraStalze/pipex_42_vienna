/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:41:34 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/24 10:59:19 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	find;
	int				strlen;

	strlen = ft_strlen(s);
	find = (unsigned char) c;
	while (strlen + 1 > 0)
	{
		if (s[strlen] == find)
			return ((char *)s + strlen);
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

	printf("i found at adress: %p %p\n", ft_strrchr(original, find1), 
		strrchr(original, find1));
	printf("u found at adress: %p %p\n", 
		ft_strrchr(original, find2), strrchr(original, find2));
	printf("1 found at adress: %p %p\n", 
		ft_strrchr(original, find3), strrchr(original, find3));

	printf("i found at adress (e. string): %p %p\n", 
		ft_strrchr(original2, find1), strrchr(original2, find1));
}
*/
