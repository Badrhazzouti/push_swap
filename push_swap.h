/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 02:22:42 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/04 02:41:57 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <string.h>

typedef struct list
{
	int	i;
	struct list *link;
} t_node;

typedef struct stacks
{
	t_node	**stack_a;
	t_node	**stack_b;
} t_stack;

typedef	struct arr
{
	int	chunk;
	int	*arr;
	int	*arr_copy;
	int	size;
	int	mid;
} t_array;

void			check_double(t_node **head_a);
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
t_node			*lst_new(int data);
void			lst_addfront(t_node **lst, t_node *new);
void			ft_lstadd_back(t_node **lst, t_node *new);
void			ft_lstclear(t_node **lst, void (*del)(void *));
int				*ft_memcpy(int *dest, int *src, size_t n);
void			ft_lstdelete(t_node **head, int data);
// void			ft_lstdelone(t_node *lst, void (*del)(void *));
void			ft_lstiter(t_node *lst, void (*f)(void *));
t_node			*ft_lstlast(t_node *lst);
int				ft_lstsize(t_node *lst);
int				ft_atoi(char *str);
int				calc_words(char *s, char c);
int				ft_wordlen(char *s, int i, char c);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_charge(char *s, int i, char c);
void			*freeini(char **string, int len);
char			**ft_split(char *s, char sep);
void			split_to_node(t_node **head, char *str);
char			*ft_strchr(char *s, int c);

# endif