/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:57:59 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/20 01:59:43 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_array(t_stack **a)
{
	t_stack	*tmp;
	int		*arr;
	int		i;

	arr = malloc ((ft_lstsize(*a) + 1) * sizeof(int));
	i = 0;
	tmp = *a;
	while (tmp)
	{
		arr[i] = tmp->i;
		tmp = tmp->link;
		i++;
	}
	return (arr);
}

void	two(t_stack **a)
{
	int	data;

	data = (*a)->link->i;
	if ((*a)->i > data)
		sa(a);
}

int	get_min(t_stack **a, int *i)
{
	t_stack	*fake;
	int		min;

	min = (*a)->i;
	fake = *a;
	while (fake)
	{
		if (fake->i < min)
			min = fake->i;
		fake = fake->link;
	}
	fake = *a;
	*i = 0;
	while (fake && fake->i != min)
	{
		(*i)++;
		fake = fake->link;
	}
	return (min);
}

int	check_sorted_a(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp && tmp->link && tmp->i < tmp->link->i)
		tmp = tmp->link;
	if (tmp->link == NULL)
		return (0);
	return (1);
}

void	sort_3(t_stack **a)
{
	if ((*a)->i > (*a)->link->i && (*a)->link->i > (*a)->link->link->i)
	{
		sa((a));
		rra(a);
	}
	else if ((*a)->i > (*a)->link->i && (*a)->link->i < (*a)->link->link->i
		&& (*a)->i > (*a)->link->link->i)
		ra(a);
	else if ((*a)->i > (*a)->link->i && (*a)->link->i < (*a)->link->link->i
		&& (*a)->i < (*a)->link->link->i)
		sa((a));
	else if ((*a)->i < (*a)->link->i && (*a)->link->i > (*a)->link->link->i
		&& (*a)->i > (*a)->link->link->i)
		rra(a);
	else if ((*a)->i < (*a)->link->i && (*a)->link->i > (*a)->link->link->i
		&& (*a)->i < (*a)->link->link->i)
	{
		rra(a);
		sa((a));
	}
}
