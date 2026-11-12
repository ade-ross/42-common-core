/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale <ale@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:11:17 by ale               #+#    #+#             */
/*   Updated: 2025/01/27 01:00:14 by ale              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b == NULL)
		return ;
	temp = (*stack_b)->next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = temp;
	ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a == NULL)
		return ;
	temp = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = temp;
	ft_printf("pb\n");
}
