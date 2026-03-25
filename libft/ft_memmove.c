/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:23:15 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/28 15:38:55 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	i = 0;
	if (d > s)
	{
		while (n != 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	else if (d < s)
	{
		while (n--)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char testS1[] = "42vienna";
	printf("Before: %s\n", testS1);
	printf("Test overlap d > s: %s\n", 
		(char *)ft_memmove(testS1 + 3, testS1, 6));

	char testS2[] = "42vienna_is_the_bbest";
	printf("Before: %s\n", testS2);
	printf("Test overlap d < s: %s\n", 
		(char *)ft_memmove(testS2, testS2 + 3, 10));

	char testS3[40] = "42vienna";
	printf("Before: %s\n", testS3);
	printf("Test overlap d > s but no overlap: %s\n\n", 
		(char *)ft_memmove(testS3 + 30, testS3, 6));

	char testS5[] = "42vienna";
	printf("Before: %s\n", testS5);
	printf("Test overlap d > s: %s\n", 
		(char *)memmove(testS5 + 3, testS5, 6));

	char testS6[] = "42vienna_is_the_bbest";
	printf("Before: %s\n", testS6);
	printf("Test overlap d < s: %s\n", 
		(char *)memmove(testS6, testS6 + 3, 10));

	char testS7[40] = "42vienna";
	printf("Before: %s\n", testS7);
	printf("Test overlap d > s but no overlap: %s\n", 
		(char *)memmove(testS7 + 30, testS7, 6));
}
*/
