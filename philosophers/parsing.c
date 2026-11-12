/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:51:23 by ale               #+#    #+#             */
/*   Updated: 2025/03/28 16:51:42 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_input_h(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (j == 0 && argv[i][j] == '+')
			j++;
		if (j == 0 && argv[i][j] == '-' && argv[i][j + 1] != '\0')
		{
			printf("input non valido\n");
			return (0);
		}
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				printf("input non valido\n");
				return (0);
			}
			j++;
		}
	}
	return (1);
}

int	check_input(char **argv, int argc)
{
	if (!(argc == 5 || argc == 6))
	{
		printf("necessari 4 o 5 argomenti\n");
		return (0);
	}
	if (check_input_h(argv, argc) == 0)
		return (0);
	return (1);
}
