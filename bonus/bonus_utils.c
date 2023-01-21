/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:03:46 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/21 00:07:23 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->link != NULL)
		lst = lst->link;
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->link;
		count++;
	}
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	unsigned char	ch;
	int				i;

	ch = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return (&s[i]);
		i++;
	}
	if (!ch)
		return (&s[i]);
	return (0);
}

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
