/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:54:13 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/21 03:00:39 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_check(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		if (ft_isdigit(splited[i]) == 0)
			w_error();
		i++;
	}
	if (i == 0)
		w_error();
}

void	args_check(t_sp spl, int ac, char **av)
{
	while (spl.j < ac)
	{
		spl.split = ft_split(av[spl.j], ' ');
		error_check(spl.split);
		my_free(spl.split);
		spl.j++;
	}
}

void	which_instruction(char *instru, t_stack **a, t_stack **b)
{
	if (check_sorted_a(a) == 0 && !b)
		return ;
	instructions_maker(instru, a, b);
}

void	my_instructions(int fd, t_stack **a, t_stack **b)
{
	char	*instru;

	instru = get_next_line(fd);
	while (instru)
	{
		which_instruction(instru, a, b);
		free(instru);
		instru = get_next_line(fd);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_sp	spl;

	spl.i = 1;
	spl.j = 1;
	b = NULL;
	if (ac == 1)
		exit (0);
	args_check(spl, ac, av);
	a = get_stack(ac, av);
	my_instructions(0, &a, &b);
	if (check_sorted_a(&a) == 0 && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
