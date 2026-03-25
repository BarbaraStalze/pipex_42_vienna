/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:00:33 by bastalze          #+#    #+#             */
/*   Updated: 2025/11/05 10:44:30 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**ft_free(char **a, int j)
{
	while (j >= 0)
	{
		free(a[j]);
		a[j] = 0;
		j--;
	}
	free(a);
	a = 0;
	return (0);
}

static char	**ft_string(char const *s, char c)
{
	int		s_count;
	int		i;
	char	**string;

	i = 0;
	s_count = 0;
	while (s[s_count])
	{
		if (s[s_count] != c)
		{
			i++;
			while (s[s_count] && s[s_count] != c)
				s_count++;
		}
		else
			s_count++;
	}
	string = malloc((i + 1) * sizeof(char *));
	if (!string)
	{
		return (0);
	}
	return (string);
}

static char	*ft_extract_stubstring(char const *s, char c, int *s_count)
{
	int	i;
	int	start;

	start = *s_count;
	i = 0;
	while (s[start + i] && s[start + i] != c)
		i++;
	start = start + i;
	*s_count = start;
	return (ft_substr(s, (start - i), (size_t) i));
}

static char	**ft_substring(char const *s, char c)
{
	int		s_count;
	char	**string;
	int		j;

	string = ft_string(s, c);
	if (!string)
		return (0);
	s_count = 0;
	j = 0;
	while (s[s_count])
	{
		if (s[s_count] != c)
		{
			string[j] = ft_extract_stubstring(s, c, &s_count);
			if (!string[j])
				return (ft_free(string, j - 1));
			j++;
		}
		else
			s_count++;
	}
	string[j] = 0;
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = ft_substring(s, c);
	return (array);
}

/*
#include <stdio.h>
int main(void)
{	
	int i;
	char const s[] = ",,,,,,,,";
	char c = ',';
	char **array = ft_split(s, c);

	if (!array)
		printf("Original string: %s\n", *array);
	i = 0;
	while (array[i])
	{
		printf("Trimmed string %c: %s\n", i, array[i]);
		i++;
	}
}
*/
