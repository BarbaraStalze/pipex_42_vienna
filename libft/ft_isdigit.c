/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:39:08 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/29 12:32:29 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
int main (void)
{
	printf ("MF: %d\n", ft_isdigit('h'));
	printf ("MF: %d\n", ft_isdigit('5'));
	printf ("MF: %d\n", ft_isdigit(0));
	printf ("OF: %d\n", isdigit('h'));
	printf ("OF: %d\n", isdigit('5'));
	printf ("OF: %d\n", isdigit(0));
}
*/
