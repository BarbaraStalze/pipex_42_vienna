/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:58:28 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/24 14:47:06 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	size_t	start;
	size_t	set_count;

	start = 0;
	while (s1[start])
	{
		set_count = 0;
		while (set[set_count])
		{
			if (set[set_count] == s1[start])
				break ;
			set_count++;
		}
		if (set_count == ft_strlen(set))
			return ((int)start);
		start++;
	}
	return (0);
}

static int	ft_end(char const *s1, char const *set)
{
	size_t	end;
	size_t	set_count;

	end = ft_strlen(s1);
	while (s1[end - 1])
	{
		set_count = 0;
		while (set[set_count])
		{
			if (set[set_count] == s1[end - 1])
				break ;
			set_count++;
		}
		if (set_count == ft_strlen(set))
			return ((int)end - 1);
		end--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*trim;

	start = ft_start (s1, set);
	end = ft_end (s1, set);
	if (start > end)
		return (ft_strdup(""));
	len = end - start + 1;
	trim = ft_substr(s1, start, len);
	if (!trim)
		return (0);
	return (trim);
}

/*
#include <stdio.h>
int main(void)
{
	char const s1[] = "";
	char const set[] = "12";
	printf("Original string: %s\n", s1);
	printf("Trimmed string: %s\n", ft_strtrim(s1, set));
}
*/
