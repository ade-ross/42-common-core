/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 02:09:52 by ale               #+#    #+#             */
/*   Updated: 2025/02/08 18:27:20 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_last_two(t_list **st_a, t_list **st_b)
{
	if ((*st_b)->content < (*st_a)->content)
		pa(st_a, st_b);
	else if ((*st_b)->content > (ft_lstlast(*st_a))->content)
	{
		pa(st_a, st_b);
		ra(st_a);
	}
	else if ((*st_b)->content > (*st_a)->content && \
		(*st_b)->content < (*st_a)->next->content)
	{
		ra(st_a);
		pa(st_a, st_b);
		rra(st_a);
	}
	else if ((*st_b)->content > (*st_a)->next->content && \
		(*st_b)->content < (ft_lstlast(*st_a))->content)
	{
		rra(st_a);
		pa(st_a, st_b);
		ra(st_a);
		ra(st_a);
	}
}
/* #include <stdio.h>

void prnt(int n)
{
	printf("%d ", n);
} */

void	push_last_one_h(t_list **st_a, t_list **st_b)
{
	ra(st_a);
	pa(st_a, st_b);
	sa(st_a);
	rra(st_a);
}

//da modificare se coi va solo se ce ne sono 3 nella lista
void	push_last_one(t_list **st_a, t_list **st_b)
{
	if ((*st_b)->content < (*st_a)->content)
		pa(st_a, st_b);
	else if ((*st_b)->content > (ft_lstlast(*st_a))->content)
	{
		pa(st_a, st_b);
		ra(st_a);
	}
	else if ((*st_b)->content > (*st_a)->content && \
		(*st_b)->content < (*st_a)->next->content)
	{
		ra(st_a);
		pa(st_a, st_b);
		rra(st_a);
	}
	else if ((*st_b)->content > (*st_a)->next->content && \
		(*st_b)->content < (*st_a)->next->next->content)
		push_last_one_h(st_a, st_b);
	else if ((*st_b)->content > (*st_a)->next->next->content && \
		(*st_b)->content < (ft_lstlast(*st_a))->content)
	{
		rra(st_a);
		pa(st_a, st_b);
		ra(st_a);
		ra(st_a);
	}
}

void	sort_for_bigger_five(t_list **st_a, t_list **st_b)
{
	int	len;

	len = ft_lstsize(*st_a);
	if (len == 2)
	{
		if ((*st_a)->content > (*st_a)->next->content)
			sa(st_a);
	}
	else
	{
		while (len-- > 3)
			pb(st_a, st_b);
		sort_for_three(st_a);
		if (ft_lstsize(*st_b) == 2)
			push_last_two(st_a, st_b);
		if (ft_lstsize(*st_b) == 1)
			push_last_one(st_a, st_b);
	}
}

//ordinamento piu efficiente se stack ha solo 3 elementi
void	sort_for_three(t_list **st_a)
{
	t_list	*sc;

	sc = (*st_a)->next;
	if ((*st_a)->content > sc->content && \
	(*st_a)->content < sc->next->content && sc->content < sc->next->content)
		sa(st_a);
	else if ((*st_a)->content > sc->content && \
	(*st_a)->content > sc->next->content && sc->content > sc->next->content)
	{
		sa(st_a);
		rra(st_a);
	}
	else if ((*st_a)->content > sc->next->content && \
	(*st_a)->content > sc->next->content && sc->content < sc->next->content)
		ra(st_a);
	else if ((*st_a)->content < sc->content && \
	(*st_a)->content < sc->next->content && sc->content > sc->next->content)
	{
		sa(st_a);
		ra(st_a);
	}
	else if ((*st_a)->content < sc->content && \
	(*st_a)->content > sc->next->content && sc->content > sc->next->content)
		rra(st_a);
}
