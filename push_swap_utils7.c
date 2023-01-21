/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:02:46 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/20 02:03:15 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_stack **a, t_stack **b, t_array *array)
{
	int	guest;

	initialize_array(array);
	while (*a)
	{
		guest = 0;
		while (in_range(a, array, &guest) == 1)
		{
			while (!((*a)->i >= array->arr[array->start]
					&& (*a)->i <= array->arr[array->end])
				&& guest <= ft_lstsize(*a) / 2)
				ra(a);
			while (!((*a)->i >= array->arr[array->start]
					&& (*a)->i <= array->arr[array->end])
				&& guest > ft_lstsize(*a) / 2)
				rra(a);
			pb(a, b);
			if ((*b)->i < array->arr[array->mid])
				rb(b);
			guest = 0;
		}
		update_array(array);
	}
}

int	in_range_b(t_stack **b, int max)
{
	t_stack	*tmp;

	tmp = *b;
	while (tmp)
	{
		if (tmp->i == max)
			return (1);
		tmp = tmp->link;
	}
	return (0);
}

void	pa_ra(t_stack **a, t_stack **b, int *guest)
{
	pa(a, b);
	ra(a);
	(*guest)++;
}

void	rb_rrb(t_stack **b, t_array *array, int index)
{
	index = get_index(array->arr[array->size - 1], b);
	if (index <= ft_lstsize(*b) / 2)
		rb(b);
	if (index > ft_lstsize(*b) / 2)
		rrb(b);
}

void	optimize(t_stack **a, int *guest, t_array *array)
{
	rra(a);
	(*guest)--;
	array->size--;
}
