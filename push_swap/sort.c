/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 02:03:34 by ale               #+#    #+#             */
/*   Updated: 2025/02/07 22:30:30 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//trova indice del numero piu grande di tutti
int	biggest_n_idx(t_list *stack)
{
	int	i;
	int	idx;

	i = 0;
	idx = i;
	while (stack && stack->next)
	{
		i++;
		if (stack->content < stack->next->content)
			idx = i;
		stack = stack->next;
	}
	return (idx);
}

void	order_st_b(t_list **st_b, int idx, int len)
{
	int	i;

	i = 0;
	if (idx <= (len / 2))
	{
		while (i < idx)
		{
			rb(st_b);
			i++;
		}
	}
	else
	{
		idx = len - idx;
		while (i < idx)
		{
			rrb(st_b);
			i++;
		}
	}
}

void	push_in_st_a(t_list **st_a, t_list **st_b)
{
	while (*st_b != NULL)
		pa(st_a, st_b);
}

int	is_ordered(t_list *st_a)
{
	while (st_a->next)
	{
		if (st_a->content > st_a->next->content)
			return (0);
		st_a = st_a->next;
	}
	return (1);
}

//ordina i numeri e fa i check sull'imput
void	sort_numbers(t_list **st_a, t_list **st_b)
{
	if (!(*st_a))
		return ;
	if (is_ordered(*st_a))
		return ;
	if (ft_lstsize(*st_a) > 5)
	{
		while (ft_lstsize(*st_b) < 2)
			pb(st_a, st_b);
		while (*st_a)
		{
			if (find_best_and_push(st_a, st_b) == 0)
			{
				write(2, "malloc failed", 13);
				return ;
			}
		}
		order_st_b(st_b, biggest_n_idx(*st_b), ft_lstsize(*st_b));
		push_in_st_a(st_a, st_b);
	}
	else if (ft_lstsize(*st_a) > 1)
		sort_for_bigger_five(st_a, st_b);
}
