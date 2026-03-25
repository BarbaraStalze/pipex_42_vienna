/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:01:24 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/28 15:36:23 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_null(void)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;
	long	m;

	m = n;
	if (n == 0)
		return (ft_null());
	len = ft_len(n);
	str = malloc(len + 1);
	if (!str)
		return (0);
	if (m < 0)
	{
		str[0] = '-';
		m = -m;
	}
	i = len - 1;
	while (m > 0)
	{
		str[i--] = (m % 10) + 48;
		m /= 10;
	}
	str[len] = 0;
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	int n = -2147483648;
	printf("Number int: %d\nNumber char str: %s", n, ft_itoa(n));
}
*/
