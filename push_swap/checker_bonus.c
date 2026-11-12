/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:21:37 by ale               #+#    #+#             */
/*   Updated: 2025/02/08 20:39:00 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_command_exist_and_do_it(char *s, t_list **st_a, t_list **st_b)
{
	if (ft_strncmp(s, "sa\n", 3) == 0)
		sa_b(st_a);
	else if (ft_strncmp(s, "sb\n", 3) == 0)
		sb_b(st_b);
	else if (ft_strncmp(s, "ss\n", 3) == 0)
		ss_b(st_a, st_b);
	else if (ft_strncmp(s, "ra\n", 3) == 0)
		ra_b(st_a);
	else if (ft_strncmp(s, "rb\n", 3) == 0)
		rb_b(st_b);
	else if (ft_strncmp(s, "rrr\n", 4) == 0)
		rrr_b(st_a, st_b);
	else if (ft_strncmp(s, "rra\n", 4) == 0)
		rra_b(st_a);
	else if (ft_strncmp(s, "rrb\n", 4) == 0)
		rrb_b(st_b);
	else if (ft_strncmp(s, "rr\n", 3) == 0)
		rr_b(st_a, st_b);
	else if (ft_strncmp(s, "pa\n", 3) == 0)
		pa_b(st_a, st_b);
	else if (ft_strncmp(s, "pb\n", 3) == 0)
		pb_b(st_a, st_b);
	else
		return (error());
	return (1);
}

int	write_result(int flag, t_list **st_a, t_list **st_b)
{
	if (flag == 1)
		write(1, "OK\n", 3);
	else if (flag == 2)
		write(1, "KO\n", 3);
	ft_lstclear(st_a);
	ft_lstclear(st_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*st_a;
	t_list	*st_b;
	char	*s;

	st_a = NULL;
	st_b = NULL;
	if (create_list(argc, argv, &st_a) == 0)
		return (ft_lstclear(&st_a), 0);
	s = get_next_line(STDIN_FILENO);
	while (s != NULL)
	{
		if (check_command_exist_and_do_it(s, &st_a, &st_b) == 1)
			free(s);
		else
			return (free(s), 0);
		s = get_next_line(STDIN_FILENO);
	}
	free(s);
	if (is_ordered(st_a) == 1 && st_b == NULL)
		return (write_result(1, &st_a, &st_b));
	else
		return (write_result(2, &st_a, &st_b));
}
