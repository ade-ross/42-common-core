/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:02:54 by ade-ross          #+#    #+#             */
/*   Updated: 2025/03/28 16:37:28 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_is_dead(t_data *all)
{
	int	i;

	pthread_mutex_lock(&(((t_data *)all)->dead_lock));
	i = ((t_data *)all)->is_dead;
	pthread_mutex_unlock(&(((t_data *)all)->dead_lock));
	return (i);
}

int	philosopher_h(void *all, t_philo *philo, int ph_n)
{
	pthread_mutex_lock(&(((t_data *)all)->printf_lock));
	printf("%ld %d is sleeping\n", \
		(get_time() - ((t_data *)all)->started_eating), ph_n);
	pthread_mutex_unlock(&(((t_data *)all)->printf_lock));
	pthread_mutex_unlock(&(philo->prev->fork));
	pthread_mutex_unlock(&(philo->fork));
	usleep(((t_data *)all)->tts * 1000);
	if (check_is_dead(all) == 1)
		return (0);
	pthread_mutex_lock(&(((t_data *)all)->printf_lock));
	printf("%ld %d is thinking\n", \
		(get_time() - ((t_data *)all)->started_eating), ph_n);
	pthread_mutex_unlock(&(((t_data *)all)->printf_lock));
	pthread_mutex_lock(&(((t_data *)all)->cycle_lock));
	(((t_data *)all)->cur_cycle[ph_n]) = (((t_data *)all)->cur_cycle[ph_n]) + 1;
	pthread_mutex_unlock(&(((t_data *)all)->cycle_lock));
	return (1);
}

void	initialize_i(int *i, void *all)
{
	pthread_mutex_lock(&(((t_data *)all)->iseven_lock));
	(*i) = 0;
	if (((t_data *)all)->is_even == 1)
		(*i)++;
	pthread_mutex_unlock(&(((t_data *)all)->iseven_lock));
}
// void try(t_data *all, t_philo *philo, int ph_n)
// {
// /*
// 	pthread_mutex_t first_fork;
// 	if (ph_n != all->n_phils)
// 		first_fork = philo->prev->fork;
// 	else
// 		return ; */

// 	pthread_mutex_lock(&(first_fork));
// 	pthread_mutex_lock(&(philo->fork));
// 	usleep(all->tte * 1000);
// 	pthread_mutex_unlock(&(philo->fork));
// 	pthread_mutex_unlock(&(first_fork));
// }

void	*philosopher(void *philo)
{
	int	i;
	int	ph_n;

	pthread_mutex_lock(&(((t_philo *)philo)->all->position_lock));
	initialize_i(&i, ((t_philo *)philo)->all);
	while (((t_philo *)philo)->all->position[i] == 1)
		i += 2;
	((t_philo *)philo)->all->position[i] = 1;
	ph_n = i + 1;
	pthread_mutex_unlock(&(((t_philo *)philo)->all->position_lock));
	pthread_mutex_lock(&(((t_philo *)philo)->all->cycle_lock));
	((t_philo *)philo)->all->cur_cycle[ph_n] = 0;
	pthread_mutex_unlock(&(((t_philo *)philo)->all->cycle_lock));
	while (((t_philo *)philo)->all->cur_cycle[ph_n] < \
			((t_philo *)philo)->all->cycles)
	{
		if (try_to_eat((((t_philo *)philo)->all), (t_philo *)philo, i) == 0)
			return (NULL);
		if (philosopher_h(((t_philo *)philo)->all, (t_philo *)philo, ph_n) == 0)
			return (NULL);
	}
	return (NULL);
}
