/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:06:00 by bastalze          #+#    #+#             */
/*   Updated: 2025/11/03 11:28:04 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	minus;
	int	rtrn;

	minus = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' || nptr[i]
		== '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			minus = (-1);
		i++;
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	rtrn = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		rtrn = rtrn * 10 + (nptr[i] - 48);
		i++;
	}
	return (rtrn * minus);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	printf("%d\n", ft_atoi("   846udg"));
	printf("%d\n", ft_atoi("74500"));
	printf("%d\n", ft_atoi("+8675  "));
	printf("%d\n", ft_atoi("       -6z8u"));
	printf("%d\n", ft_atoi(""));

	printf("\nOriginal function:\n");
	printf("%d\n", atoi("   846udg"));
	printf("%d\n", atoi("74500"));
	printf("%d\n", atoi("+8675  "));
	printf("%d\n", atoi("       -6z8u"));
	printf("%d\n", atoi(""));
}*/
