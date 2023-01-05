/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:27:48 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/02 05:03:08 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double(t_node **head_a)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = *head_a;
	while (tmp->link != NULL)
	{
		tmp2 = tmp;
		while (tmp2->link != NULL)
		{
			if (tmp->i == tmp2->link->i)
			{
				printf("Error\nDuplicated number %d and %d !!\n", tmp->i, tmp2->link->i);
				exit (1);
			}
			tmp2 = tmp2->link;
		}
		tmp = tmp->link;
	}
}
