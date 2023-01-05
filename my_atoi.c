/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:07:17 by bhazzout          #+#    #+#             */
/*   Updated: 2022/12/30 16:37:26 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_outsider(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9')
		{
			ft_printf("Error, outsider %c!!\n", str[i]);
			exit (1);
		}
		else
			i++;
	}
}

void	check_int(int r, int sign)
{
	if (r > 32767 && (sign == 1))
	{
		ft_printf("Error\n");
		exit (1);
	}
	else if (r - 1 > 32767 && (sign == -1))
	{
		ft_printf("Error\n");
		exit (1);
	}
}

int	check_sign(int s)
{
	int	sign;

	sign = 0;
	if (s % 2 == 0)
		sign = 1;
	else if (s % 2 != 0)
		sign = -1;
	return (sign);
}

int	ft_atoi(char *str)
{
	int				i;
	int				s;
	int				sign;
	int				r;

	check_outsider(str);
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	s = 0;
	while (str[i] == '-')
	{
			s++;
			i++;
	}
	sign = check_sign(s);
	if (str[i] == '+')
		i++;
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (check_int(r, sign), (r * sign));
}
