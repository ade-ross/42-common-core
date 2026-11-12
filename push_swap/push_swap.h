/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:06:23 by ade-ross          #+#    #+#             */
/*   Updated: 2024/11/27 00:15:33 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>
# include "time.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(int));
t_list	*ft_lstmap(t_list *lst, int (*f)(int));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);

t_list	*ft_lstsearchwnext(t_list *lst, t_list *nxt);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

int		ft_printf(const char *str, ...);
int		ft_putptr1(unsigned long nb);
int		ft_putptr(unsigned long p);
int		ft_putnbr_x(unsigned int nb, char c);
int		ft_printf1(va_list args, const char *str, int *flag);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putnbr_u(unsigned int nb);
int		ft_putstr(char *str);

void	populate_st_a(int **pos_st_a, int n);

int		min(int a, int b);
int		smallest(t_list *stack);

void	put_pos(int j, int i, int **pos_st_b, int n1);
int		lit_ma_mi(t_list *lst, int n_to_compare);
int		is_or_op(t_list *st_a);
void	pop_st_b_i(int **pos_st_b, int i, t_list *st_a, t_list *st_b);
void	populate_st_b(int **pos_st_b, int n, t_list *st_a, t_list *st_b);

int		modul(int n);
int		max(int a, int b);
void	find_best_i_to_move_h(int *i, int *idx, int **pos_st_a, \
		int **pos_st_b);
int		find_best_idx_to_move(int **pos_st_a, int **pos_st_b, int n);

void	push_best_idx_help(int i, int j, t_list **st_a, t_list **st_b);
void	push_best_idx(int i, int j, t_list **st_a, t_list **st_b);
int		find_best_and_push(t_list **st_a, t_list **st_b);

int		biggest_n_idx(t_list *stack);
void	order_st_b(t_list **st_b, int idx, int len);
void	push_in_st_a(t_list **st_a, t_list **st_b);
int		is_ordered(t_list *st_a);
void	sort_numbers(t_list **st_a, t_list **st_b);

void	push_last_two(t_list **st_a, t_list **st_b);
void	sort_for_bigger_five(t_list **st_a, t_list **st_b);
void	sort_for_three(t_list **st_a);

int		n_is_present(int new, int n);
void	ft_lstiter_mod(t_list *lst, int *flag, int new_num, int (*f)(int, int));

int		check_min_int(char *s);
int		check_max_int(char *s);
int		initial_checks(char **argv, int i);
int		create_list(int argc, char **argv, t_list **st_a);

//void	*ft_memset(int **s, int c, int n);

int		error(void);
int		ft_strlen(const char *s);

void	ft_lstdelone(t_list *lst);

int		ft_atoi(const char *nptr);

#endif
