/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_instructions3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:38:24 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/21 03:00:18 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
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

void	instructions_maker(char *instru, t_stack **a, t_stack **b)
{
	if (ft_strcmp(instru, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(instru, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(instru, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(instru, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(instru, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(instru, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(instru, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(instru, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(instru, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(instru, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(instru, "rrr\n") == 0)
		rrr(a, b);
	else
		w_error();
}
