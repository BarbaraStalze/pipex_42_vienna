/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:09:18 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/24 14:44:01 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void ft_toupper_wrapper(unsigned int i, char *s)
{
	(void) i;
	*s = ft_toupper(*s);
}

#include <stdio.h>
int main()
{
	char s[] = "Hello my name is";
	
	ft_striteri(s, ft_toupper_wrapper);
	printf("%s", s);
}
*/
