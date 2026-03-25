/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:20:53 by bastalze          #+#    #+#             */
/*   Updated: 2025/11/14 16:27:30 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_s(char *s, int *count)
{
	int	i;

	if (!s)
	{
		write (1, "(null)", 6);
		*count = *count + 6;
		return ;
	}
	i = 0;
	while (s[i])
	{
		i++;
		(*count)++;
	}
	write (1, s, i);
}
