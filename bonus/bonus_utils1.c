/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:05:47 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/21 00:09:09 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
