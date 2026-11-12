/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:21:42 by ale               #+#    #+#             */
/*   Updated: 2025/02/08 20:39:16 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b == NULL)
		return ;
	temp = (*stack_b)->next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = temp;
}

void	pb_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a == NULL)
		return ;
	temp = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = temp;
}
