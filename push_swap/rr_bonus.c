/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:20:26 by ale               #+#    #+#             */
/*   Updated: 2025/02/08 20:39:26 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra_b(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp1;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	temp1 = ft_lstlast(*stack_a);
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	temp1->next = temp;
}

void	rb_b(t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp1;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	temp1 = ft_lstlast(*stack_b);
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	temp1->next = temp;
}

void	rr_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp1;

	if (*stack_a == NULL || (*stack_a)->next == NULL || \
		*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_a;
	temp1 = ft_lstlast(*stack_a);
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	temp1->next = temp;
	temp = *stack_b;
	temp1 = ft_lstlast(*stack_b);
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	temp1->next = temp;
}
