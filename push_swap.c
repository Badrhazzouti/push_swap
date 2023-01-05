/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 02:22:10 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/06 00:26:56 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init(t_stack *stack)
{
	stack = malloc (sizeof (t_stack));
	stack->stack_a = malloc (sizeof(t_node *));
	stack->stack_b = malloc (sizeof(t_node *));
	*(stack->stack_a) = NULL;
	*(stack->stack_b) = NULL;
	return (stack);
}

void	pa(int av, t_node **stack_a, t_node **stack_b)
{
	if (stack_b == NULL)
		return ;
	lst_addfront(stack_a, lst_new(av));
	ft_lstdelete(stack_b, av);
	write(1, "pa\n", 3);
}

void	pb(int av, t_node **stack_b, t_node **stack_a)
{
	if (stack_a == NULL)
		return ;
	lst_addfront(stack_b, lst_new(av));
	ft_lstdelete(stack_a, av);
	write(1, "pb\n", 3);
}

void	ra(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*last_node;

	tmp = *stack_a;
	*stack_a = (*stack_a)->link;
	last_node = ft_lstlast(*stack_a);
	last_node->link = tmp;
	tmp->link = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*last_node;

	tmp = *stack_b;
	*stack_b = (*stack_b)->link;
	last_node = ft_lstlast(*stack_b);
	last_node->link = tmp;
	tmp->link = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}

t_node	*sa(t_node *stack_a)
{
	int	tmp;
	if (stack_a->link == NULL || !stack_a)
		return (stack_a);
	tmp = stack_a->link->i;
	stack_a->link->i = stack_a->i;
	stack_a->i = tmp;
	write(1, "sa\n", 3);
	return (stack_a);
}

t_node	*sb(t_node *stack_b)
{
	int	tmp;

	if (stack_b->link == NULL || !stack_b)
		return (stack_b);
	tmp = stack_b->link->i;
	stack_b->link->i = stack_b->i;
	stack_b->i = tmp;
	write(1, "sb\n", 3);
	return (stack_b);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	*stack_a = sa(*stack_a);
	*stack_b = sb(*stack_b);
	ft_printf("ss\n");
}

void	rra(t_node **stack_a)
{
	t_node	*current;
	t_node	*tmp;

	current = *stack_a;
	while (current->link->link != NULL)
		current = current->link;
	tmp = current->link;
	current->link = NULL;
	tmp->link = *stack_a;
	*stack_a = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*current;

	current = *stack_b;
	while (current->link->link != NULL)
		current = current->link;
	tmp = current->link;
	current->link = NULL;
	tmp->link = *stack_b;
	*stack_b = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}

int	*tmp_arr(t_node **av, int ac)
{
	t_node	*current;
	int		*arr;
	int		i;

	arr = malloc (sizeof(ac - 1));
	current = *av;
	i = 0;
	while (current != NULL)
	{
		arr[i] = current->i;
		current = current->link;
		i++;
	}
	return (arr);
}

void	swap(int *arr, int *arr2)
{
	int	tmp;

	tmp = *arr;
	*arr = *arr2;
	*arr2 = tmp;
}

void	 arr_sort(int *arr, int ac)
{
	int	sorted;
	int	i;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < ac - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i],&arr[i + 1]);
				sorted = 0;
			}
			i++;
		}
	}
}

int	get_index(int data, t_node **stack_a)
{
	t_node	*current;
	int		index;

	index = 1;
	current = *stack_a;
	while (current != NULL)
	{
		if (current->i == data)
			return (index);
		current = current->link;
		index++;
	}
	return (0);
}

void	print_arr(int *array)
{
	int	i;
	
	i = 0;
	while (array[i])
	{
		printf("array : %d\n", array[i]);
		i++;
	}
	printf("\n----\n");
}

void print_list(t_node *stack, char c)
{
	ft_printf("STACK %c : %d\n", c, ft_lstsize(stack));
	while (stack)
	{
		ft_printf(" [%d]\n", stack->i);
		stack = stack->link;
	}
	ft_printf("\n");
}

void	data_over_mid(t_node **stack_a, int *arr, t_node **stack_b, int devid)
{
	int	size;
	int	iteration;

	size = ft_lstsize(*stack_a);
	iteration = size;
	while (iteration != 0)
	{
		if ((*stack_a)->i >= arr[0] && (*stack_a)->i <= arr[size / devid - 1])
			pb((*stack_a)->i, stack_b, stack_a);
		else
			ra(stack_a);
		iteration--;
	}
	if (devid != 2)
		data_over_mid(stack_a, arr + size / devid, stack_b, devid - 1);
}

void	check_range(int	data, t_node **stack_b, t_node **stack_a)
{
	int	index;
	int	to_index;

	index = get_index(data, stack_b);
	to_index = 0;
	if (index <= ft_lstsize(*stack_b) / 2)
	{
		while (to_index++ != index)
		{
			if ((*stack_b)->i == data)
				pa((*stack_b)->i, stack_a, stack_b);
			else
				rb(stack_b);
		}
	}
	else
	{
		while (to_index++ != index)
		{
			if ((*stack_b)->i == data)
				pa((*stack_b)->i, stack_a, stack_b);
			else
				rb(stack_b);
		}
	}
}

void	sort_b(t_node **stack_b, int *arr, t_node **stack_a)
{
	int		size;
	int		i;
	t_node	*tmp;

	size = ft_lstsize(*stack_b);
	i = size - 1;
	while (i != -1)
	{
		tmp = *stack_b;
		while (tmp != NULL)
		{
			if (arr[i] == tmp->i)
				check_range(tmp->i, stack_b, stack_a);
			tmp = tmp->link;
		}
		i--;
	}
}

void	check_sorted_av(int ac, char **av)
{
	int	i;
	int	checker;

	i = 1;
	checker = 1;
	if (ac >= 2)
	{
		while (i < ac - 1)
		{
			if (ft_atoi(av[i]) < ft_atoi(av[i + 1]))
				checker++;
			i++;
		}
		if (checker == ac - 1)
		{
			exit (1);
		}
	}
	else
	{
		exit (1);
	}
}

void	sort_3(t_stack *stack)
{

	if ((*stack->stack_a)->i > (*stack->stack_a)->link->i && (*stack->stack_a)->link->i > (*stack->stack_a)->link->link->i)
	{
		sa((*stack->stack_a));
		rra(stack->stack_a);
	}
	else if ((*stack->stack_a)->i > (*stack->stack_a)->link->i && (*stack->stack_a)->link->i < (*stack->stack_a)->link->link->i && (*stack->stack_a)->i > (*stack->stack_a)->link->link->i)
		ra(stack->stack_a);
	else if ((*stack->stack_a)->i > (*stack->stack_a)->link->i && (*stack->stack_a)->link->i < (*stack->stack_a)->link->link->i && (*stack->stack_a)->i < (*stack->stack_a)->link->link->i)
		sa((*stack->stack_a));
	else if ((*stack->stack_a)->i < (*stack->stack_a)->link->i && (*stack->stack_a)->link->i > (*stack->stack_a)->link->link->i && (*stack->stack_a)->i > (*stack->stack_a)->link->link->i)
		rra(stack->stack_a);
	else if ((*stack->stack_a)->i < (*stack->stack_a)->link->i && (*stack->stack_a)->link->i > (*stack->stack_a)->link->link->i && (*stack->stack_a)->i < (*stack->stack_a)->link->link->i)
	{
		rra(stack->stack_a);
		sa((*stack->stack_a));
	}
}

void	normal_sort_10(t_stack *stack, t_array *array)
{
	int	i;
	int	index;
	// int	*arr_copy = NULL;
	int	default_size;

	default_size = ft_lstsize((*stack->stack_a));
	// arr_copy = malloc (sizeof (int) * default_size);
	i = 0;
	while (array->arr[i + 3])
	{
		index = get_index(array->arr[i], stack->stack_a);
		if (index == 2 && ft_lstsize((*stack->stack_a)) == 2)
		{
			sa((*stack->stack_a));
			index--;
		}
		while (index > 1 && index <= ft_lstsize((*stack->stack_a)) / 2)
		{
			ra(stack->stack_a);
			index--;
		}
		while ((index > 1 && index <= ft_lstsize((*stack->stack_a))) && index > ft_lstsize((*stack->stack_a)) / 2)
		{
			rra(stack->stack_a);
			index++;
			if (index == ft_lstsize((*stack->stack_a)))
			{
				rra(stack->stack_a);
				index = 1;
			}
		}
		if ((*stack->stack_a)->i == array->arr[i])
			pb((*stack->stack_a)->i, stack->stack_b, stack->stack_a);
		i++;
	}
	if (ft_lstsize((*stack->stack_a)) == 3)
		sort_3(stack);
	while (ft_lstsize((*stack->stack_a)) < default_size)
		pa((*stack->stack_b)->i, stack->stack_a, stack->stack_b);
}

void	for100_sort_10(t_stack *stack, t_array *array, int start, int end)
{
	int	i;
	int	index;
	// int	*arr_copy = NULL;
	int	default_size;

	default_size = ft_lstsize((*stack->stack_a));
	// arr_copy = malloc (sizeof (int) * default_size);
	
	i = 0;
	// printf("this is array->arr[start] : %d\n", array->arr[start + 3]);
	while (array->arr[start] != array->arr[end - 3])
	{
		index = get_index(array->arr[start], stack->stack_a);
		if (index == 2 && ft_lstsize((*stack->stack_a)) == 2)
		{
			sa((*stack->stack_a));
			index--;
		}
		while (index > 1 && index <= ft_lstsize((*stack->stack_a)) / 2)
		{
			ra(stack->stack_a);
			index--;
		}
		while ((index > 1 && index <= ft_lstsize((*stack->stack_a))) && index > ft_lstsize((*stack->stack_a)) / 2)
		{
			rra(stack->stack_a);
			index++;
			if (index == ft_lstsize((*stack->stack_a)))
			{
				rra(stack->stack_a);
				index = 1;
			}
		}
		if ((*stack->stack_a)->i == array->arr[start])
			pb((*stack->stack_a)->i, stack->stack_b, stack->stack_a);
		start++;
	}
	if (ft_lstsize((*stack->stack_a)) == 3)
		sort_3(stack);
	while (ft_lstsize((*stack->stack_a)) < default_size)
		pa((*stack->stack_b)->i, stack->stack_a, stack->stack_b);
}

void	sort_40(t_stack *stack, t_array *array, int chunk_size)
{
	int	i;

	i = array->size - chunk_size;
	while (array->arr[i] < array->arr[array->size - 10])
	{
		while ((*stack->stack_a)->i >= array->arr[array->size - 10])
		{
			ra(stack->stack_a);
		}
		if (ft_lstlast((*stack->stack_a))->i < array->arr[array->size - 10])
			rra(stack->stack_a);
		if ((*stack->stack_a)->i < array->arr[array->size - 10] && (*stack->stack_a)->i >= array->arr[array->size - chunk_size])
			pb((*stack->stack_a)->i, stack->stack_b, stack->stack_a);
		i++;
	}
}

int	get_max(t_node *stack_b)
{
	t_node *tmp;
	int		max;

	tmp = stack_b;
	while (tmp)
	{
		max = tmp->i;
		if (tmp->link->i > tmp->i)
			max = tmp->link->i;
		tmp = tmp->link;
	}
	return (max);
}

void	push_back_a(t_stack *stack, t_array *array, int last_chunk)
{
	int	i;
	int	index;
	int	j;

	i = last_chunk - array->chunk;
	j = last_chunk;
	while (array->arr[i] < array->arr[j + 1])
	{
		index = get_index(array->arr[j], stack->stack_b);
		if (index == 2 && ft_lstsize((*stack->stack_b)) == 2)
		{
			sb((*stack->stack_b));
			index--;
		}
		while (index > 1 && index <= ft_lstsize((*stack->stack_b)) / 2)
		{
			rb(stack->stack_b);
			index--;
		}
		while ((index > 1 && index <= ft_lstsize((*stack->stack_b))) && index > ft_lstsize((*stack->stack_b)) / 2)
		{
			rrb(stack->stack_b);
			index++;
			if (index == ft_lstsize((*stack->stack_b)))
			{
				rra(stack->stack_b);
				index = 1;
			}
		}
		if ((*stack->stack_b)->i == array->arr[j])
			pa((*stack->stack_b)->i, stack->stack_a, stack->stack_b);
		j--;
	}
	// if (ft_lstsize((*stack->stack_b)) > 0)
	// 	push_back_a(stack, array, last_chunk - array->chunk);
}

void	push_back(t_stack *stack, t_array *array)
{
	(void) stack;
	printf("the max in S_B : %d\n", array->arr[90 - 1]);
}

void	sort_100(t_stack *stack, t_array *array, int chunk_size)
{
	int	i;
	int	*current_array;

	current_array = malloc (sizeof(int) * array->size);
	current_array = array->arr;
	i = 0;
	while (i < 30)
	{
		while ((*stack->stack_a)->i >= array->arr[chunk_size])
			ra(stack->stack_a);
		if (ft_lstlast((*stack->stack_a))->i < array->arr[chunk_size])
			rra(stack->stack_a);
		if ((*stack->stack_a)->i < array->arr[chunk_size])
			pb((*stack->stack_a)->i, stack->stack_b, stack->stack_a);
		i++;
	}
	if (ft_lstsize((*stack->stack_a)) > 40)
		sort_100(stack, array, chunk_size + array->chunk);
	if (ft_lstsize((*stack->stack_a)) == 40)
		sort_40(stack, array, 40);
	else if (ft_lstsize((*stack->stack_a)) == 10)
		for100_sort_10(stack, array, array->size - 10, array->size);
}

int main (int ac, char **av)
{
	t_stack	*stack;
	t_array	*array;
	int		i;

	stack = NULL;
	stack = init(stack);
	array = malloc (sizeof (t_array));
	array->arr = malloc (sizeof(int) * (ac - 1));
	int		*arr2;
	arr2 = malloc (sizeof(int) * (ac - 1));

	check_sorted_av(ac, av);
	i = 1;
	while (i < ac)
	{
		split_to_node(stack->stack_a, av[i]);
		i++;
	}
	check_double(stack->stack_a);
	array->arr = tmp_arr(stack->stack_a, ac);
	arr_sort(array->arr, ac - 1);
	array->chunk = 30;
	array->size = ft_lstsize((*stack->stack_a));
	if (ac == 4)
		sort_3(stack);
	else if (ac == 11)
		normal_sort_10(stack, array);
	else
	{
		sort_100(stack, array, array->chunk);
		push_back(stack, array);
		// push_back_a(stack, array, array->size - 10);
		// push_back_a(stack, array, array->size - array->chunk - 10);
		// push_back_a(stack, array, array->size - array->chunk - array->chunk - 10);
	}
	// printf("size of S_B 1: %d\n",ft_lstsize((*stack->stack_b)));
	// push_back_a(stack, array, array->size - array->chunk - 10); 
	// printf("size of S_B 2: %d\n",ft_lstsize((*stack->stack_b)));
	// push_back_a(stack, array, array->size - array->chunk - array->chunk - 10);
	// printf("size of S_B 3: %d\n",ft_lstsize((*stack->stack_b)));
	// push_back_a(stack, array, ac -1);
	print_list(*(stack->stack_a), 'A');
	print_list(*(stack->stack_b), 'B');
	return (0);
}
