/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale <ale@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:03:06 by ale               #+#    #+#             */
/*   Updated: 2025/01/19 02:07:50 by ale              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

// finds smallest number in stack
int	smallest(t_list *stack)
{
	int	mn;

	mn = min(stack->content, stack->next->content);
	stack = stack->next;
	while (stack->next)
	{
		mn = min(mn, min(stack->content, stack->next->content));
		stack = stack->next;
	}
	return (mn);
}
