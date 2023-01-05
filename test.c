#include "push_swap.h"

t_node	*lst_new(int data)
{
	t_node *lst;

	lst = malloc (sizeof(t_node));
	lst->i = data;
	lst->link = NULL;
	return (lst);
}

void	lst_addfront(t_node **lst, t_node *new)
{
	new->link = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*lastnode;

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

// void	ft_lstclear(t_node **lst, void (*del)(void *))
// {
// 	t_node	*new;

// 	if (!del || !lst)
// 		return ;
// 	while (lst && *lst)
// 	{
// 		new = (*lst)->link;
// 		ft_lstdelone(*lst, del);
// 		*lst = new;
// 	}
// }

// void	ft_lstdelone(t_node *lst, void (*del)(void *))
// {
// 	if (!del || !lst)
// 		return ;
// 	if (lst)
// 	{
// 		(*del)((lst->i));
// 		free(lst);
// 	}
// }

void	ft_lstdelete(t_node **head, int data)
{
	t_node	*current;
	t_node	*tmp;

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

void	ft_lstiter(t_node *lst, void (*f)(void *))
{
	if (!f || !lst)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->link;
	}
}

t_node	*ft_lstlast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->link != NULL)
		lst = lst->link;
	return (lst);
}

int	ft_lstsize(t_node *lst)
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
