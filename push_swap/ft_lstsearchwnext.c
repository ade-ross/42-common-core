/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearchwnext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale <ale@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:20:01 by ale               #+#    #+#             */
/*   Updated: 2024/12/30 23:34:06 by ale              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//cerca l'elemento della lista che come next il t_list nxt
//usato in rrr.c per trovare il penultimo elemento avendo l'ultimo

t_list	*ft_lstsearchwnext(t_list *lst, t_list *nxt)
{
	if (lst == 0)
		return (NULL);
	while (lst->next != nxt)
	{
		lst = lst->next;
	}
	return (lst);
}
