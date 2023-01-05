/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printff_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 03:06:51 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/01 23:25:16 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}

int	ft_puthex(unsigned int k, int lU)
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
		ft_puthex(k, lU);
		count++;
	}
	else if (k >= 16)
	{
		count += ft_puthex((k / 16), lU);
		count += ft_putchar(hex[(k % 16)]);
	}
	else
		count += ft_putchar(hex[k]);
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += ft_putstr("-2147483648");
	else if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
		count += ft_putnbr(n);
	}
	else if (n > 9)
	{
		count += ft_putnbr((n / 10));
		count += ft_putchar((n % 10) + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

void	split_to_node(t_node **head, char *str)
{
	char	**split;

	if (ft_strchr(str, '	'))
		split = ft_split(str, '	');
	else
		split = ft_split(str, ' ');
	while (*split)
	{
		ft_lstadd_back(head, lst_new(ft_atoi(*split)));
		split++;
	}
}
