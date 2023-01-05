/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 03:05:55 by bhazzout          #+#    #+#             */
/*   Updated: 2022/12/20 03:06:09 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_puthexa(size_t k, int lU)
{
	int		count;
	char	*hex;

	count = 0;
	if (lU == 0)
		hex = "0123456789abcdef";
	else if (lU == 1)
		hex = "0123456789ABCDEF";
	if (k < 0)
	{
		ft_putchar('-');
		k = -k;
		ft_puthexa(k, lU);
		count++;
	}
	else if (k >= 16)
	{
		count += ft_puthexa((k / 16), lU);
		count += ft_putchar(hex[(k % 16)]);
	}
	else
		count += ft_putchar(hex[k]);
	return (count);
}

int	ft_putadd(size_t k)
{
	write(1, "0x", 2);
	return (ft_puthexa(k, 0) + 2);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write (1, "(null)", 6));
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

unsigned int	ft_putunsi(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putunsi((n / 10));
		count += ft_putchar((n % 10) + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}
