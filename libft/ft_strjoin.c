/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:55:17 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/28 15:28:56 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_string(char *string, char const *s1, int s1len)
{
	int	i;

	i = 0;
	while (s1len > 0)
	{
		string[i] = s1[i];
		i++;
		s1len--;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*string;
	int		i;
	int		j;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	string = malloc(s1len + s2len + 1);
	if (!string)
		return (0);
	i = ft_string(string, s1, s1len);
	j = 0;
	while (s2len > 0)
	{
		string[i] = s2[j];
		i++;
		j++;
		s2len--;
	}
	string[i] = 0;
	return (string);
}

/*
#include <stdio.h>
int main(void)
{
	char const s1[] = "Just ";
	char const s2[] = "do it!";

	printf("Concatinated string = %s", ft_strjoin(s1, s2));
}
*/
