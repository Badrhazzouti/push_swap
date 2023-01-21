/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:52:41 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/20 01:53:13 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}

int	get_index(int data, t_stack **stack)
{
	t_stack	*current;
	int		index;

	index = 1;
	current = *stack;
	while (current != NULL)
	{
		if (current->i == data)
			return (index);
		current = current->link;
		index++;
	}
	return (0);
}

void	w_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
