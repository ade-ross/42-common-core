/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ph_are_alive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:01:13 by ale               #+#    #+#             */
/*   Updated: 2025/03/26 19:20:56 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_phil_is_dead(void *all, int i)
{
	pthread_mutex_lock(&(((t_data *)all)->dead_lock));
	if ((get_time() - ((t_data *)all)->last_started_eating[i]) - 5 > \
		((t_data *)all)->ttd)
	{
		((t_data *)all)->is_dead = 1;
		pthread_mutex_unlock(&(((t_data *)all)->dead_lock));
		pthread_mutex_lock(&(((t_data *)all)->printf_lock));
		printf("%ld %d died\n", \
			(get_time() - ((t_data *)all)->started_eating), i);
		pthread_mutex_unlock(&(((t_data *)all)->printf_lock));
		return (0);
	}
	pthread_mutex_unlock(&(((t_data *)all)->dead_lock));
	return (1);
}
//only needed to avoid norminette line_to_long on line 55
void	stupid_ft(void *all)
{
	pthread_mutex_unlock(&(((t_data *)all)->cycle_lock));
}

void	*check_phs_are_alive(void *all)
{
	int	i;
	int	tot_cycles;
	int	current_cycles;

	tot_cycles = ((t_data *)all)->n_phils * ((t_data *)all)->cycles;
	current_cycles = 0;
	while (1)
	{
		i = 1;
		while (i <= ((t_data *)all)->n_phils)
		{
			pthread_mutex_lock(&(((t_data *)all)->cycle_lock));
			if (((t_data *)all)->cur_cycle[i] >= ((t_data *)all)->cycles)
			{
				current_cycles = current_cycles + ((t_data *)all)->cycles;
				if (current_cycles >= tot_cycles)
					return (stupid_ft(all), NULL);
			}
			pthread_mutex_unlock(&(((t_data *)all)->cycle_lock));
			if (check_phil_is_dead(all, i) == 0)
				return (NULL);
			i++;
		}
	}
}
