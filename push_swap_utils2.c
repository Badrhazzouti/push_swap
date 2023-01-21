/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:50:50 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/20 02:35:01 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b)
{
	if (*b != NULL && (*b)->link != NULL)
	{
		swap(&(*b)->i, &(*b)->link->i);
		write (1, "sb\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = (*a)->link;
	lst_addfront(b, lst_new((*a)->i));
	free(*a);
	*a = tmp;
	write(1, "pb\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (*b != NULL && (*b)->link != NULL)
	{
		tmp1 = (*b)->link;
		tmp = ft_lstlast(*b);
		tmp->link = *b;
		(*b)->link = NULL;
		*b = tmp1;
		write(1, "rb\n", 3);
	}
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (*b != NULL && (*b)->link != NULL)
	{
		tmp1 = *b;
		while (tmp1)
		{
			if (tmp1->link->link == NULL)
				break ;
			tmp1 = tmp1->link;
		}
		tmp = ft_lstlast(*b);
		tmp1->link = NULL;
		tmp->link = *b;
		*b = tmp;
		write(1, "rrb\n", 4);
	}
}
