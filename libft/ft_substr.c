/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:41:21 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/28 14:29:10 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subp;
	unsigned int	slen;
	int				i;

	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	subp = malloc(len + 1);
	if (!subp)
		return (0);
	i = 0;
	while (s[start] != 0 && len > 0)
	{
		subp[i] = s[start];
		i++;
		start++;
		len--;
	}
	subp[i] = 0;
	return (subp);
}

/*
#include <stdio.h>
int main(void)
{
	char const string[] = "It's getting hot in here";
	unsigned int start = 13;
	size_t l = 3;

	printf("Substring: %s\n", ft_substr(string, start, l));

	start = 30;
	printf("Substring: %s\n", ft_substr(string, start, l));

	start = 20;
	l = 10;
	printf("Substring: %s\n", ft_substr(string, start, l));
}
*/
