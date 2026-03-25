/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:39:08 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/22 11:49:31 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
int main (void)
{
	printf ("MF: %d\n", ft_isalnum('7'));
	printf ("MF: %d\n", ft_isalnum('+'));
	printf ("OF: %d\n", isalnum('7'));
	printf ("OF: %d\n", isalnum('+'));
}
*/
