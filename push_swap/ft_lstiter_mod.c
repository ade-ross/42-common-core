/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:57:57 by ade-ross          #+#    #+#             */
/*   Updated: 2025/01/21 20:58:52 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n_is_present(int new, int n)
{
	if (n == new)
		return (1);
	else
		return (0);
}

//lstiter modificato per cercare se un numero e gia prensente nella stack
void	ft_lstiter_mod(t_list *lst, int *flag, int new_num, int (*f)(int, int))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		*flag = f(new_num, lst->content);
		if (*flag == 1)
			return ;
		lst = lst->next;
	}
}
