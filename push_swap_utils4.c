/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:54:39 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/20 01:55:50 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_check(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		if (ft_isdigit(splited[i]) == 0)
			w_error();
		i++;
	}
	if (i == 0)
		w_error();
}

void	my_free(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

void	args_check(t_sp spl, int ac, char **av)
{
	while (spl.j < ac)
	{
		spl.split = ft_split(av[spl.j], ' ');
		error_check(spl.split);
		my_free(spl.split);
		spl.j++;
	}
}

void	check_repeated(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *stack;
	while (tmp)
	{
		tmp1 = tmp->link;
		while (tmp1)
		{
			if (tmp->i == tmp1->i)
				w_error();
			tmp1 = tmp1->link;
		}
		tmp = tmp->link;
	}
}

t_stack	*get_stack(int ac, char **av)
{
	t_stack	*stack;
	char	**tmp;
	int		i;
	int		x;

	i = 1;
	stack = NULL;
	while (i < ac)
	{
		x = 0;
		tmp = ft_split(av[i], ' ');
		while (tmp[x])
		{
			ft_lstadd_back(&stack, lst_new(ft_atoi(tmp[x])));
			x++;
		}
		my_free(tmp);
		i++;
	}
	check_repeated(&stack);
	return (stack);
}
