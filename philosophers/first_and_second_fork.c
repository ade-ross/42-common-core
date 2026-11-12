/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_and_second_fork.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:18:44 by ade-ross          #+#    #+#             */
/*   Updated: 2025/03/28 16:37:10 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	try_sec_fork_even(t_data *all, t_philo *philo, int ph_n)
{
	pthread_mutex_lock(&(philo->prev->fork));
	pthread_mutex_lock(&(all->dead_lock));
	((t_data *)all)->last_started_eating[ph_n] = get_time();
	pthread_mutex_unlock(&(all->dead_lock));
	if (check_is_dead(all) == 1)
	{
		return ;
	}
	pthread_mutex_lock(&(all->printf_lock));
	printf("%ld %d has taken a fork\n", \
		(get_time() - all->started_eating), ph_n);
	printf("%ld %d is eating\n", \
		(get_time() - all->started_eating), ph_n);
	pthread_mutex_unlock(&(all->printf_lock));
	usleep(all->tte * 1000);
}

void	try_sec_fork_odd(t_data *all, t_philo *philo, int ph_n)
{
	pthread_mutex_lock(&(philo->fork));
	pthread_mutex_lock(&(all->dead_lock));
	((t_data *)all)->last_started_eating[ph_n] = get_time();
	pthread_mutex_unlock(&(all->dead_lock));
	if (check_is_dead(all) == 1)
	{
		return ;
	}
	pthread_mutex_lock(&(all->printf_lock));
	printf("%ld %d has taken a fork\n", \
		(get_time() - all->started_eating), ph_n);
	printf("%ld %d is eating\n", \
		(get_time() - all->started_eating), ph_n);
	pthread_mutex_unlock(&(all->printf_lock));
	usleep(all->tte * 1000);
}

void	try_first_fork_even(t_data *all, t_philo *philo, int i)
{
	int	ph_n;

	ph_n = i + 1;
	pthread_mutex_lock(&(philo->fork));
	if (check_is_dead(all) == 1)
	{
		return ;
	}
	pthread_mutex_lock(&(all->printf_lock));
	printf("%ld %d has taken a fork\n", \
		(get_time() - all->started_eating), ph_n);
	pthread_mutex_unlock(&(all->printf_lock));
}

void	try_first_fork_odd(t_data *all, t_philo *philo, int i)
{
	int	ph_n;

	ph_n = i + 1;
	pthread_mutex_lock(&(philo->prev->fork));
	if (check_is_dead(all) == 1)
	{
		return ;
	}
	pthread_mutex_lock(&(all->printf_lock));
	printf("%ld %d has taken a fork\n", \
		(get_time() - all->started_eating), ph_n);
	pthread_mutex_unlock(&(all->printf_lock));
}
