/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:19:32 by ale               #+#    #+#             */
/*   Updated: 2025/02/08 20:39:35 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra_b(t_list **stack_a)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp1 = ft_lstlast(*stack_a);
	temp2 = ft_lstsearchwnext(*stack_a, temp1);
	temp2->next = NULL;
	temp1->next = *stack_a;
	*stack_a = temp1;
}

void	rrb_b(t_list **stack_b)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp1 = ft_lstlast(*stack_b);
	temp2 = ft_lstsearchwnext(*stack_b, temp1);
	temp2->next = NULL;
	temp1->next = *stack_b;
	*stack_b = temp1;
}

void	rrr_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*stack_a == NULL || (*stack_a)->next == NULL || \
		*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp1 = ft_lstlast(*stack_a);
	temp2 = ft_lstsearchwnext(*stack_a, temp1);
	temp2->next = NULL;
	temp1->next = *stack_a;
	*stack_a = temp1;
	temp1 = ft_lstlast(*stack_b);
	temp2 = ft_lstsearchwnext(*stack_b, temp1);
	temp2->next = NULL;
	temp1->next = *stack_b;
	*stack_b = temp1;
}
