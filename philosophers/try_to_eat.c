/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:05:02 by ade-ross          #+#    #+#             */
/*   Updated: 2025/03/26 19:19:06 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	try_to_eat_odd(t_data *all, t_philo *philo, int i)
{
	if (check_is_dead(all) == 1)
		return (0);
	try_first_fork_odd(all, philo, i);
	if (check_is_dead(all) == 1)
	{
		pthread_mutex_unlock(&(((t_philo *)philo)->prev->fork));
		return (0);
	}
	if (all->n_phils > 1)
		try_sec_fork_odd(all, philo, (i + 1));
	else
	{
		pthread_mutex_unlock(&(((t_philo *)philo)->prev->fork));
		while (check_is_dead(all) != 1)
			;
		return (0);
	}
	if (check_is_dead(all) == 1)
	{
		pthread_mutex_unlock(&(((t_philo *)philo)->prev->fork));
		pthread_mutex_unlock(&(((t_philo *)philo)->fork));
		return (0);
	}
	return (1);
}

int	try_to_eat_even(t_data *all, t_philo *philo, int i)
{
	if (check_is_dead(all) == 1)
		return (0);
	try_first_fork_even(all, philo, i);
	if (check_is_dead(all) == 1)
	{
		pthread_mutex_unlock(&(((t_philo *)philo)->fork));
		return (0);
	}
	if (all->n_phils > 1)
		try_sec_fork_even(all, philo, (i + 1));
	else
	{
		pthread_mutex_unlock(&(((t_philo *)philo)->fork));
		while (check_is_dead(all) != 1)
			;
		return (0);
	}
	if (check_is_dead(all) == 1)
	{
		pthread_mutex_unlock(&(((t_philo *)philo)->fork));
		pthread_mutex_unlock(&(((t_philo *)philo)->prev->fork));
		return (0);
	}
	return (1);
}

int	try_to_eat(t_data *all, t_philo *philo, int i)
{
	int	ph_n;
	int	ret;

	ph_n = i + 1;
	if (ph_n / 2 != 0)
		ret = try_to_eat_odd(all, philo, i);
	else
		ret = try_to_eat_even(all, philo, i);
	return (ret);
}
