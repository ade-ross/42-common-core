/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:07:01 by ale               #+#    #+#             */
/*   Updated: 2025/03/28 16:45:05 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialize_started_eating_time(t_data	*all)
{
	int	i;

	i = 0;
	while (i < 202)
	{
		all->last_started_eating[i] = get_time();
		i++;
	}
	i = 0;
	while (i < 202)
	{
		all->cur_cycle[i] = 0;
		i++;
	}
}

void	initialize_positions(t_data *all)
{
	int	i;

	i = -1;
	while (++i < 202)
		all->position[i] = 0;
}

int	initialize_all(t_data *all, char **argv, int argc)
{
	all->n_phils = ft_atoi(argv[1]);
	if (all->n_phils <= 0)
		return (printf("input non valido\n"), 0);
	all->ttd = ft_atoi(argv[2]);
	if (all->ttd <= 0)
		return (printf("input non valido\n"), 0);
	all->tte = ft_atoi(argv[3]);
	if (all->tte <= 0)
		return (printf("input non valido\n"), 0);
	all->tts = ft_atoi(argv[4]);
	if (all->tts <= 0)
		return (printf("input non valido\n"), 0);
	if (argc == 6)
		all->cycles = ft_atoi(argv[5]);
	else
		all->cycles = __INT_MAX__;
	if (all->cycles <= 0)
		return (printf("input non valido\n"), 0);
	all->is_dead = 0;
	all->is_even = 0;
	initialize_started_eating_time(all);
	initialize_positions(all);
	return (1);
}
