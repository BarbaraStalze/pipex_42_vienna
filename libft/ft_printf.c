/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:24:20 by bastalze          #+#    #+#             */
/*   Updated: 2026/04/06 13:44:44 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_format_specifier(const char *text, int *count, va_list arg)
{
	if (*text == 'c')
		ft_c(va_arg(arg, int), count);
	else if (*text == 's')
		ft_s(va_arg(arg, char *), count);
	else if (*text == 'p')
		ft_p(va_arg(arg, size_t), count);
	else if (*text == 'd' || *text == 'i')
		ft_d_i(va_arg(arg, int), count);
	else if (*text == 'u')
		ft_u(va_arg(arg, unsigned int), count);
	else if (*text == 'x' || *text == 'X')
		ft_hex(va_arg(arg, unsigned int), count, *text);
	else if (*text == '%')
	{
		write (1, "%", 1);
		(*count)++;
	}
	else
		*count = -1;
}

static void	ft_print_text(const char *text, int *count, va_list arg)
{
	int	i;

	i = 0;
	while (text[i])
	{
		if (text[i] == '%')
		{
			ft_format_specifier(&text[i + 1], count, arg);
			if (*count == -1)
				return ;
			i = i + 2;
		}
		else
		{
			write(1, &text[i], 1);
			i++;
			(*count)++;
		}
	}
}

int	ft_printf(const char *text, ...)
{
	va_list	arg;
	int		count;

	if (!text)
		return (-1);
	count = 0;
	va_start(arg, text);
	ft_print_text(text, &count, arg);
	va_end(arg);
	return (count);
}
