/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 02:08:58 by ale               #+#    #+#             */
/*   Updated: 2025/02/08 19:29:36 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_min_int(char *s)
{
	char	*i_min;
	int		i;

	i_min = "-2147483648";
	i = 0;
	if (s[0] == '-')
		i++;
	if (ft_strlen(s) > 11)
		return (0);
	else if ((s[0] == '-') && ft_strlen(s) == 11)
	{
		while (i < ft_strlen(s))
		{
			if ((s[i] - 48) > (i_min[i] - 48))
				return (0);
			if ((s[i] - 48) < (i_min[i] - 48))
				return (1);
			i++;
		}
	}
	return (1);
}

int	check_max_int(char *s)
{
	char	*i_max;
	int		i;
	int		j;

	i = 0;
	j = 0;
	i_max = "2147483647";
	if (s[0] == '+')
		i++;
	if ((ft_strlen(s) > 11) || \
	(s[0] != '+' && s[0] != '-' && ft_strlen(s) > 10))
		return (0);
	else if ((s[0] != '+' && s[0] != '-' && \
	ft_strlen(s) == 10) || ((s[0] == '+') && ft_strlen(s) == 11))
	{
		while (i < ft_strlen(s))
		{
			if ((s[i] - 48) > (i_max[j] - 48))
				return (0);
			if ((s[i++] - 48) < (i_max[j] - 48))
				return (1);
			j++;
		}
	}
	return (1);
}

int	initial_checks(char **argv, int i)
{
	int	j;

	j = 0;
	if (check_max_int(argv[i]) == 0 || check_min_int(argv[i]) == 0)
		return (error());
	if (argv[i][j] == '-' || argv[i][j] == '+')
		j++;
	while (argv[i][j] != '\0')
	{
		if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			return (error());
		j++;
	}
	return (1);
}

int	create_list(int argc, char **argv, t_list **st_a)
{
	int		i;
	t_list	*temp;
	int		flag;

	i = 1;
	flag = 0;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (initial_checks(argv, i) == 0)
			return (0);
		temp = ft_lstnew(ft_atoi(argv[i]));
		if (!temp)
			return (0);
		ft_lstiter_mod(*st_a, &flag, temp->content, n_is_present);
		if (flag == 0)
			ft_lstadd_back(st_a, temp);
		else
			return (free(temp), (error()));
		i++;
	}
	return (1);
}
