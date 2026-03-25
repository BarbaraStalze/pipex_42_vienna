/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:39:08 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/28 15:34:22 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
int main (void)
{
	printf ("My function: %d\n", ft_isalpha('h'));
	printf ("My function: %d\n", ft_isalpha('+'));
	printf ("Original function: %d\n", isalpha('h'));
	printf ("Original function: %d\n", isalpha('+'));
}
*/
