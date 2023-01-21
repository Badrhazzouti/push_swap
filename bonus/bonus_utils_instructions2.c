/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_instructions2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:32:42 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/21 02:30:17 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sa(t_stack **a)
{
	if (*a != NULL && (*a)->link != NULL)
	{
		swap(&(*a)->i, &(*a)->link->i);
	}
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = (*b)->link;
	lst_addfront(a, lst_new((*b)->i));
	free(*b);
	*b = tmp;
}

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (*a == NULL || (*a)->link == NULL)
		return ;
	tmp1 = (*a)->link;
	tmp = ft_lstlast(*a);
	tmp->link = *a;
	(*a)->link = NULL;
	*a = tmp1;
}

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (*a == NULL || (*a)->link == NULL)
		return ;
	tmp1 = *a;
	while (tmp1)
	{
		if (tmp1->link->link == NULL)
			break ;
		tmp1 = tmp1->link;
	}
	tmp = ft_lstlast(*a);
	tmp1->link = NULL;
	tmp->link = *a;
	*a = tmp;
}
