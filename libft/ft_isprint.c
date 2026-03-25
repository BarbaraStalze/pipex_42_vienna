/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:39:08 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/22 11:57:28 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
int main (void)
{
	printf ("MF: %d\n", ft_isprint(127));
	printf ("MF: %d\n", ft_isprint('+'));
	printf ("OF: %d\n", isprint(127));
	printf ("OF: %d\n", isprint('+'));
}
*/
