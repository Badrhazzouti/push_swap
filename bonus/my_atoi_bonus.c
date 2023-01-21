/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:10:44 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/21 00:14:55 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i && !str[i])
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	check_outsider(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9')
		{
			write(2, "Error\n", 6);
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
		write(2, "Error\n", 6);
		exit (1);
	}
	else if (r - 1 > 32767 && (sign == -1))
	{
		write(2, "Error\n", 6);
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
