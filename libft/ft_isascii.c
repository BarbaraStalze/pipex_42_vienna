/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:39:08 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/22 11:53:42 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
int main (void)
{
	printf ("MF: %d\n", ft_isascii('h'));
	printf ("MF: %d\n", ft_isascii(-1));
	printf ("MF: %d\n", ft_isascii(230));
	printf ("OF: %d\n", isascii('h'));
	printf ("OF: %d\n", isascii(-1));
	printf ("OF: %d\n", isascii(230));
}
*/
