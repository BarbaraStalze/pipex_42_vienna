/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:27:35 by bastalze          #+#    #+#             */
/*   Updated: 2025/10/23 16:50:55 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <strings.h>
#include <unistd.h>
int main(void)
{
	char str1[] = "Hierkommt";
	write (1, &str1, 10);
	ft_bzero (str1, 5);
	write (1, "\n", 1);	
	write (1, &str1, 10);

	write (1, "\n", 1);
	write (1, "\n", 1);

	char str2[] = "Hierkommt";
	write (1, &str2, 10);
	bzero (str2, 5);
	write (1, "\n", 1);
	write (1, &str2, 10);
}
*/
