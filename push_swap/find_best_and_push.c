/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_and_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:53:52 by ale               #+#    #+#             */
/*   Updated: 2025/01/21 20:44:12 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//trovato su find_best_idx_to_move l'indice con la coppia di numeri
//piu conveniente pusho il numero corrispondente
void	push_best_idx_help(int i, int j, t_list **st_a, t_list **st_b)
{
	while (i > 0)
	{
		ra(st_a);
		i--;
	}
	while (j > 0)
	{
		rb(st_b);
		j--;
	}
	while (i < 0)
	{
		rra(st_a);
		i++;
	}
	while (j < 0)
	{
		rrb(st_b);
		j++;
	}
}

void	push_best_idx(int i, int j, t_list **st_a, t_list **st_b)
{
	while (i > 0 && j > 0)
	{
		rr(st_a, st_b);
		i--;
		j--;
	}
	while (i < 0 && j < 0)
	{
		rrr(st_a, st_b);
		i++;
		j++;
	}
	push_best_idx_help(i, j, st_a, st_b);
	pb(st_a, st_b);
}

//trova il numero di stack_a che e piu conveniente pushare
// in stack_b e lo pusha
int	find_best_and_push(t_list **st_a, t_list **st_b)
{
	int	*pos_st_a;
	int	*pos_st_b;
	int	len;
	int	idx;

	len = ft_lstsize(*st_a);
	pos_st_a = malloc(len * sizeof(int));
	if (!(pos_st_a))
		return (0);
	pos_st_b = malloc(len * sizeof(int));
	if (!(pos_st_b))
		return (0);
	populate_st_a(&pos_st_a, len);
	populate_st_b(&pos_st_b, len, *st_a, *st_b);
	idx = find_best_idx_to_move(&pos_st_a, &pos_st_b, len);
	push_best_idx(pos_st_a[idx], pos_st_b[idx], st_a, st_b);
	free(pos_st_a);
	free(pos_st_b);
	return (1);
}
