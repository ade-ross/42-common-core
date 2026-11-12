/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:34:33 by ade-ross          #+#    #+#             */
/*   Updated: 2025/02/08 20:41:01 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	*ft_memset(int **s, int c, int n)
{
	int				i;
	int				*st;

	st = (int *)(*s);
	i = 0;
	while (i < n)
	{
		st[i] = c;
		i++;
	}
	return (st);
}
*/
int	main(int argc, char **argv)
{
	t_list	*st_a;
	t_list	*st_b;

	st_a = NULL;
	st_b = NULL;
	if (create_list(argc, argv, &st_a) == 0)
	{
		ft_lstclear(&st_a);
		return (0);
	}
	sort_numbers(&st_a, &st_b);
	ft_lstclear(&st_a);
	return (1);
}
/*  void	prnt(int n)
{
	printf("%d ", n);
} */
//  int	main(int argc, char **argv)
// {
// 	t_list	*st_a;
// 	t_list	*st_b;
// //	int		list_len;
// //	int		range;
// //	t_list *start;

// /* 	srand(time(NULL));
// 	range = 1000;
// 	list_len = 100;*/
// 	st_a = NULL;
// 	st_b = NULL;
// 	//t_list *st_c = NULL;
// 	//st_c = create_list_rand_n(st_c, list_len, range);
// 	//controlla di aver gestito sempre se malloc fallisce
// 	// fai caso con 2 numeri
// 	if (create_list(argc, argv, &st_a) == 0)
// 	{
// 		ft_lstclear(&st_a);
// 		return (0);
// 	}
// 	//start = st_a;
// 	/*st_a = ft_lstnew(2);
// 	t_list* due = ft_lstnew(1);
// 	st_a->next = due;
// 	t_list *tre = ft_lstnew(3);
// 	due->next = tre;
// 	t_list *quattro = ft_lstnew(35);
// 	t_list *cinque= ft_lstnew(26);
// 	tre->next = quattro;
// 	quattro->next = cinque;
// 	t_list *sei = ft_lstnew(12);
// 	cinque->next = sei;
// 	t_list *sette = ft_lstnew(6);
// 	t_list *otto= ft_lstnew(-14);
// 	sei->next = sette;
// 	sette->next = otto;
// 	t_list *nove = ft_lstnew(-20);
// 	otto->next = nove;
// 	nove->next = NULL; */

// 	/* ft_lstiter(st_a, prnt);
// 	printf("\n\n");
// 	ft_lstiter(st_b, prnt);
// 	printf("\n\n"); */

// 	sort_numbers(&st_a, &st_b);
// 	// instead of just
// 	//find_best_and_push(&st_a, &st_b);

// /* 	printf("\n\n");
// 	ft_lstiter(st_a, prnt);
// 	printf("\n\n");
// 	ft_lstiter(st_b, prnt);
// 	printf("\n\n"); */

// 	ft_lstclear(&st_a);
// 	//ft_lstclear(&st_b);

// //	printf("\nrrr\n");
// 	/* printf("\n\n");
// 	ft_lstiter(st_c, prnt); */

// 	/* printf("\n\n");
// 	printf("*count: %d", count);
// 	printf("\n\n"); */
// 	return (1);
// }
