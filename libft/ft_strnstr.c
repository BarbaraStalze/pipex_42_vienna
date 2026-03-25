/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:12:31 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/28 16:09:50 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[i] != 0 && i < len)
	{
		j = 0;
		while ((big[i + j] == little[j]) && little[j] != 0 && i + j < len)
		{
			j++;
		}
		if (little[j] == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
char *strnstr(const char *big, const char *little, size_t len);

int main()
{
	char longy[] = "Never gonna give you up...";
	char shorty[] = "you";
	char *result;

	result = ft_strnstr(longy, shorty, 25);
	printf("Haystack: %s\n", longy);
	printf("Needle: %s\n", shorty);
	printf("Result: %s\n", result);
	printf("Result original function: %s\n", strnstr(longy, shorty, 25));

	char longy2[] = "Never gonna give you up...";
	char shorty2[] = "";
	char *result2;

	result2 = ft_strnstr(longy2, shorty2, 10);
	printf("Haystack2: %s\n", longy2);
	printf("Needle2: %s\n", shorty2);
	printf("Result2: %s\n", result2);
	printf("Result original function2: %s\n", strnstr(longy2, shorty2, 10));

	char longy3[] = "";
	char shorty3[] = "what?";
	char *result3;

	result3 = ft_strnstr(longy3, shorty3, 10);
	printf("Haystack3: %s\n", longy3);
	printf("Needle3: %s\n", shorty3);
	printf("Result3: %s\n", result3);
	printf("Result original function3: %s\n", strnstr(longy3, shorty3, 10));
}
*/
