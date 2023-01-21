/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 02:22:10 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/20 23:44:15 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	down(t_stack **a, int *guest)
{
	while (*guest > 0)
	{
		rra(a);
		(*guest)--;
	}
}

void	send_to_a(t_stack **a, t_stack **b, t_array *array)
{
	int		index;
	int		guest;

	index = 0;
	guest = 0;
	while (*b)
	{
		if (in_range_b(b, array->arr[array->size - 1]) == 1)
		{
			if ((*b)->i == array->arr[array->size - 1])
			{
				pa(a, b);
				array->size--;
			}
			else if (*b && (guest == 0 || (*b)->i > ft_lstlast(*a)->i))
				pa_ra(a, b, &guest);
			else if ((*b)->i != array->arr[array->size - 1])
				rb_rrb(b, array, index);
		}
		else
			optimize(a, &guest, array);
	}
	down(a, &guest);
}

void	big(t_stack **a, t_stack **b, t_array *array)
{
	array_sort(array, a);
	send_to_b(a, b, array);
	send_to_a(a, b, array);
}

void	all_sort(t_stack **a, t_stack **b, t_array *array)
{
	array->size = ft_lstsize(*a);
	if (array->size == 2)
		two(a);
	if (array->size <= 16)
		small(a, b);
	if (array-> size > 16)
		big(a, b, array);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_array	*array;
	t_sp	spl;

	spl.i = 1;
	spl.j = 1;
	b = NULL;
	array = malloc (sizeof(t_array));
	if (ac == 1)
		exit (0);
	args_check(spl, ac, av);
	a = get_stack(ac, av);
	if (check_sorted_a(&a) == 0)
		exit(0);
	array->arr = get_array(&a);
	array->size = ft_lstsize(a);
	array->mid = array->size / 2;
	all_sort(&a, &b, array);
	return (0);
}
