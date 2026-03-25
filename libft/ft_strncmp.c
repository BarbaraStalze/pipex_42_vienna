/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:50:48 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/28 16:09:24 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != 0 && n > 0)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		n--;
	}
	if (s1[i] != s2[i] && n > 0)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	size_t len = 100;
	char str1[] = "What's going on?";
	char str2[] = "What's going on?";
	char str3[] = "";
	char str4[] = "What's up?";

	printf("Return: %d %d\n", ft_strncmp(str1, str2, len), 
		strncmp(str1, str2, len));
	printf("Return: %d %d\n", ft_strncmp(str1, str3, len), 
		strncmp(str1, str3, len));
	printf("Return: %d %d\n", ft_strncmp(str1, str4, len), 
		strncmp(str1, str4, len));
}
*/
