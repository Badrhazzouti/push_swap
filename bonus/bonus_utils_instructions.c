/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:30:10 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/21 01:35:33 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_stack **b)
{
	if (*b != NULL && (*b)->link != NULL)
	{
		swap(&(*b)->i, &(*b)->link->i);
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
	}
}
