/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 03:03:53 by bhazzout          #+#    #+#             */
/*   Updated: 2022/12/20 03:05:22 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_mycheck(va_list str, char c)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(str, int));
	else if (c == 'c')
		count += ft_putchar(va_arg(str, int));
	else if (c == 's')
		count += ft_putstr(va_arg(str, char *));
	else if (c == 'x')
		count += ft_puthex(va_arg(str, unsigned int), 0);
	else if (c == 'X')
		count += ft_puthex(va_arg(str, unsigned int), 1);
	else if (c == 'u')
		count += ft_putunsi(va_arg(str, unsigned int));
	else if (c == 'p')
		count += ft_putadd(va_arg(str, size_t));
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start (list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += ft_mycheck(list, s[i]);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end (list);
	return (count);
}
