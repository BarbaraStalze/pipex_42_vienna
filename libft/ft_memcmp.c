/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:42:36 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/28 15:37:38 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	size_t len = 10;
	char str1[] = "What's going on?";
	char str2[] = "What's going on?";
	printf("Return: %d %d\n", ft_memcmp(str1, str2, len), 
		memcmp(str1, str2, len));
	
	char str3[] = "";
	printf("Return: %d %d\n", ft_memcmp(str1, str3, len), 
		memcmp(str1, str3, len));

	char str4[] = "What's up?";
	printf("Return: %d %d\n", ft_memcmp(str1, str4, len), 
		memcmp(str1, str4, len));
}
*/
