/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_st_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:01:33 by ale               #+#    #+#             */
/*   Updated: 2025/01/21 19:21:18 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// aggiunge il numero alla pos i se j e' oltre la meta mette negativi
void	put_pos(int j, int i, int **pos_st_b, int n1)
{
	if ((j + 1) <= (n1 / 2))
		pos_st_b[0][i] = (j + 1);
	else
		pos_st_b[0][i] = (-(n1 - (j + 1)));
}

// controlla se n_to_compare e il numero piu grande o
// piu piccolo di tutti i numeri di lst
int	lit_ma_mi(t_list *lst, int n_to_compare)
{
	int		flag1;
	int		flag2;
	t_list	*start;

	start = lst;
	flag1 = 1;
	flag2 = 1;
	while (lst != NULL)
	{
		if (lst->content > n_to_compare)
			flag1 = 0;
		lst = lst->next;
	}
	lst = start;
	while (lst != NULL)
	{
		if (lst->content < n_to_compare)
			flag2 = 0;
		lst = lst->next;
	}
	if (flag1 == 1 || flag2 == 1)
	{
		return (1);
	}
	return (0);
}

//controlla se stack a é ordinato in modo
//decrescente
int	is_or_op(t_list *st_a)
{
	while (st_a->next)
	{
		if (st_a->content < st_a->next->content)
			return (0);
		st_a = st_a->next;
	}
	return (1);
}

//helper populate_st_b
void	pop_st_b_i(int **pos_st_b, int i, t_list *st_a, t_list *st_b)
{
	int	j;
	int	n1;

	j = 0;
	n1 = ft_lstsize(st_b);
	while (st_b && st_b->next && st_a)
	{
		if (j == 0 && (((ft_lstlast(st_b))->content > st_a->content && \
	st_b->content < st_a->content) || (lit_ma_mi(st_b, st_a->content) == 1 && \
		is_or_op(st_b) == 1)))
		{
			pos_st_b[0][i] = 0;
			break ;
		}
		else if ((st_b->content == smallest(st_b) && \
	(st_a->content < st_b->content || st_a->content > st_b->next->content)) || \
	(st_b->content > st_a->content && st_b->next->content < st_a->content))
		{
			put_pos(j, i, pos_st_b, n1);
			break ;
		}
		st_b = st_b->next;
		j++;
	}
}

//ogni posizione i di pos_st_b rappresenta quante mosse su stack_b
//serve fare per metterla nella posizione giusta per poter ricevere il
//il numero alla posizione i di st_a (positivi se si fa ra neg per rra)
void	populate_st_b(int **pos_st_b, int n, t_list *st_a, t_list *st_b)
{
	t_list	*start;
	int		i;

	i = 0;
	start = st_b;
	while (i < n)
	{
		st_b = start;
		pop_st_b_i(pos_st_b, i, st_a, st_b);
		st_a = st_a->next;
		i++;
	}
}
