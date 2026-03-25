/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:25:45 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/28 15:44:52 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*np;
	int		len;

	len = ft_strlen(s);
	np = malloc(len + 1);
	if (np == 0)
	{
		return (0);
	}
	len = ft_strlcpy(np, s, (size_t)len + 1);
	return (np);
}

/*
#include <stdio.h>
int main(void)
{
	const char *str = "Here comes the sun";
	printf("Original string: %s\n", str);
	printf("Copied string: %s\n", ft_strdup(str));

	const char *str2 = "";
	printf("Original string: %s\n", str2);
	printf("Copied string: %s\n", ft_strdup(str2));
}
*/
