/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:17:51 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/21 10:43:34 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*rstr;

	len = ft_strlen(s);
	rstr = malloc(len + 1);
	if (!rstr)
		return (0);
	i = 0;
	while (len--)
	{
		rstr[i] = f(i, s[i]);
		i++;
	}
	rstr[i] = 0;
	return (rstr);
}

/*
char ft_toupper_wrapper(unsigned int i, char s)
{
	(void) i;
	return (ft_toupper(s));
}

#include <stdio.h>
int main()
{
	char s[] = "Hello my name is";
	
	printf("%s", ft_strmapi(s, ft_toupper_wrapper));
}
*/
