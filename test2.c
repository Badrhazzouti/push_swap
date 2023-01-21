/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:27:48 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/20 23:35:14 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_new(int data)
{
	t_stack	*lst;

	lst = malloc (sizeof(t_stack));
	lst->i = data;
	lst->link = NULL;
	return (lst);
}

void	lst_addfront(t_stack **lst, t_stack *n)
{
	n->link = *lst;
	*lst = n;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*lastnode;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		lastnode = *lst;
		while (lastnode->link != NULL)
				lastnode = lastnode->link;
			lastnode->link = new;
	}
}

void	ft_lstdelete(t_stack **head, int data)
{
	t_stack	*current;
	t_stack	*tmp;

	current = *head;
	if (current != NULL && current->i == data)
	{
		*head = current->link;
		free(current);
		return ;
	}
	while (current->link != NULL && current->link->i != data)
		current = current->link;
	if (current->link != NULL)
	{
		tmp = current->link;
		current->link = tmp->link;
		free (tmp);
	}
}
