/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_idx_to_move.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:50:46 by ale               #+#    #+#             */
/*   Updated: 2025/01/21 19:26:21 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	modul(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	find_best_i_to_move_h(int *i, int *idx, int **pos_st_a, int **pos_st_b)
{
	static int	mn;

	if (((pos_st_a[0][*i] > 0) && (pos_st_b[0][*i]) > 0) || \
		(pos_st_a[0][*i] < 0 && pos_st_b[0][*i] < 0))
	{
		if (mn > max(modul(pos_st_a[0][*i]), modul(pos_st_b[0][*i])))
		{
			mn = max(modul(pos_st_a[0][*i]), modul(pos_st_b[0][*i]));
			*idx = *i;
		}
	}
	else
	{
		if (*i == 0)
			mn = modul(pos_st_a[0][*i]) + modul(pos_st_b[0][*i]);
		else
		{
			if (mn > (modul(pos_st_a[0][*i]) + modul(pos_st_b[0][*i])))
			{
				mn = modul(pos_st_a[0][*i]) + modul(pos_st_b[0][*i]);
				*idx = *i;
			}
		}
	}
}

//trova quale delle coppie di numeri in pos_st_a e pos_st_b e la piu bassa
// e quindi il numero a quell'indice sara il piu conveniente da pushare
//rida l'indice dei due arrai che a la coppia migliore
int	find_best_idx_to_move(int **pos_st_a, int **pos_st_b, int n)
{
	int	i;
	int	idx;

	i = 0;
	idx = 0;
	while (i < n)
	{
		find_best_i_to_move_h(&i, &idx, pos_st_a, pos_st_b);
		i++;
	}
	return (idx);
}
