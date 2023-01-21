/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:56:26 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/21 02:45:57 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <string.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct list
{
	int			i;
	struct list	*link;
}				t_stack;

typedef struct list2
{
	int			i;
	int			j;
	char		**split;
}				t_sp;

typedef struct list3
{
	int			*arr;
	int			size;
	int			offset;
	int			mid;
	int			start;
	int			end;
}				t_array;

void			instructions_maker(char *instru, t_stack **a, t_stack **b);
char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *s1);
int				ft_strcmp(char *s1, char *s2);
void			check_double(t_stack **head_a);
int				ft_isdigit(char *str);
int				ft_strlen(char *av);
char			*ft_strcpy(char *av);
int				ft_printf(const char *s, ...);
int				ft_mycheck(va_list str, char c);
int				ft_puthexa(size_t k, int lU);
int				ft_putadd(size_t k);
int				ft_putchar(char c);
int				ft_putstr(char *s);
unsigned int	ft_putunsi(unsigned int n);
int				ft_puthex(unsigned int k, int lU);
int				ft_putnbr(int n);
t_stack			*lst_new(int data);
void			lst_addfront(t_stack **lst, t_stack *n);
void			ft_lstadd_back(t_stack **lst, t_stack *new);
void			ft_lstclear(t_stack **lst, void (*del)(void *));
void			ft_lstdelete(t_stack **head, int data);
void			ft_lstiter(t_stack *lst, void (*f)(void *));
t_stack			*ft_lstlast(t_stack *lst);
int				ft_lstsize(t_stack *lst);
int				ft_atoi(char *str);
int				calc_words(char *s, char c);
int				ft_wordlen(char *s, int i, char c);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_charge(char *s, int i, char c);
void			*freeini(char **string, int len);
char			**ft_split(char *s, char sep);
void			split_to_node(t_stack **head, char *str);
char			*ft_strchr(char *s, int c);
void			swap(int *a, int *b);
void			sa(t_stack **a);
void			pa(t_stack **a, t_stack **b);
void			ra(t_stack **a);
void			rra(t_stack **a);
void			sb(t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			rb(t_stack **b);
void			rrb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rrr(t_stack **a, t_stack **b);
int				get_index(int data, t_stack **stack);
void			w_error(void);
void			error_check(char **splited);
void			my_free(char **splited);
void			args_check(t_sp spl, int ac, char **av);
void			check_repeated(t_stack **stack);
t_stack			*get_stack(int ac, char **av);
int				*get_array(t_stack **a);
void			two(t_stack **a);
int				get_min(t_stack **a, int *i);
int				check_sorted_a(t_stack **a);
void			sort_3(t_stack **a);
void			small(t_stack **a, t_stack **b);
void			array_sort(t_array *array, t_stack **a);
void			initialize_array(t_array *array);
int				in_range(t_stack **a, t_array *array, int *guest);
void			update_array(t_array *array);
void			send_to_b(t_stack **a, t_stack **b, t_array *array);
int				in_range_b(t_stack **b, int max);
void			pa_ra(t_stack **a, t_stack **b, int *guest);
void			rb_rrb(t_stack **b, t_array *array, int index);
void			optimize(t_stack **a, int *guest, t_array *array);

#endif