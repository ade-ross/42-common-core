/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:09:18 by ale               #+#    #+#             */
/*   Updated: 2025/02/08 18:40:50 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	*temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	ft_printf("sa\n");
}

void	sb(t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL || \
		*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	ft_printf("ss\n");
}
