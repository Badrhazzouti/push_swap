/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:00:45 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/20 02:01:18 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small(t_stack **a, t_stack **b)
{
	int	i;
	int	min;

	i = 0;
	while (ft_lstsize(*a) > 3)
	{
		min = get_min(a, &i);
		while ((*a)->i != min && i <= ft_lstsize(*a) / 2)
			ra(a);
		while ((*a)->i != min && i > ft_lstsize(*a) / 2)
			rra(a);
		pb(a, b);
	}
	if (check_sorted_a(a))
		sort_3(a);
	while (*b)
		pa(a, b);
}

void	array_sort(t_array *array, t_stack **a)
{
	int	sorted;
	int	i;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < ft_lstsize((*a)) - 1)
		{
			if (array->arr[i] > array->arr[i + 1])
			{
				swap(&array->arr[i], &array->arr[i + 1]);
				sorted = 0;
			}
			i++;
		}
	}
}

void	initialize_array(t_array *array)
{
	if (array->size <= 250)
		array->offset = array->size / 8;
	else
		array->offset = array->size / 18;
	array->start = array->mid - array->offset;
	array->end = array->mid + array->offset;
}

int	in_range(t_stack **a, t_array *array, int *guest)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->i >= array->arr[array->start]
			&& tmp->i <= array->arr[array->end])
			return (1);
		else
		{
			tmp = tmp->link;
			(*guest)++;
		}
	}
	return (0);
}

void	update_array(t_array *array)
{
	array->start -= array->offset;
	array->end += array->offset;
	if (array->end > array->size - 1)
		array->end = array->size - 1;
	if (array->start < 0)
		array->start = 0;
}
