/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:18:08 by ade-ross          #+#    #+#             */
/*   Updated: 2025/03/26 19:26:03 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialize_philos_locks(t_data *all, t_allphilos	*allphilos)
{
	int	i;

	i = 0;
	while (i < all->n_phils)
	{
		pthread_mutex_init(&(allphilos->philos[i].fork), NULL);
		i++;
	}
}

//serviva per andare sotto 25 linee con norminette
void	dumb_initialize(t_data *all, int i, t_allphilos *phs)
{
	phs->philos[i].prev = &(phs->philos[all->n_phils - 1]);
	phs->philos[i].all = all;
}

//ho chiamato allphilos phs per motivi di line too long
void	create_treads_first_part(t_data *all, int i, t_allphilos *phs)
{
	dumb_initialize(all, i, phs);
	pthread_create(&(phs->thread_ids[i]), NULL, philosopher, &(phs->philos[i]));
	i += 2;
	while (i < all->n_phils && all->n_phils > 1)
	{
		phs->philos[i].prev = &(phs->philos[i - 1]);
		phs->philos[i].all = all;
		pthread_create(&(phs->thread_ids[i]), NULL, \
						philosopher, &(phs->philos[i]));
		i += 2;
		usleep(20);
	}
	i = 1;
	usleep(50);
	pthread_mutex_lock(&(all->iseven_lock));
	all->is_even = 1;
	pthread_mutex_unlock(&(all->iseven_lock));
	while (i < all->n_phils && all->n_phils > 1)
	{
		phs->philos[i].prev = &(phs->philos[i - 1]);
		phs->philos[i].all = all;
		pthread_create(&(phs->thread_ids[i]), NULL, \
						philosopher, &(phs->philos[i]));
		i += 2;
	}
}

void	create_threads(t_data *all, int i)
{
	t_allphilos	allphilos;

	initialize_philos_locks(all, &allphilos);
	create_treads_first_part(all, 0, &allphilos);
	pthread_create(&(allphilos.thread_ids[201]), NULL, \
					check_phs_are_alive, all);
	i = 0;
	while (i < all->n_phils)
	{
		pthread_join(allphilos.thread_ids[i], NULL);
		i++;
	}
	pthread_join(allphilos.thread_ids[201], NULL);
	i = 0;
	while (i < all->n_phils)
	{
		pthread_mutex_destroy(&(allphilos.philos[i].fork));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	all;

	if (check_input(argv, argc) == 0 || \
		initialize_all(&all, argv, argc) == 0)
		return (0);
	pthread_mutex_init(&all.dead_lock, NULL);
	pthread_mutex_init(&all.cycle_lock, NULL);
	pthread_mutex_init(&all.position_lock, NULL);
	pthread_mutex_init(&all.iseven_lock, NULL);
	pthread_mutex_init(&all.printf_lock, NULL);
	all.started_eating = get_time();
	create_threads(&all, 0);
	pthread_mutex_destroy(&all.printf_lock);
	pthread_mutex_destroy(&all.iseven_lock);
	pthread_mutex_destroy(&all.dead_lock);
	pthread_mutex_destroy(&all.position_lock);
	pthread_mutex_destroy(&all.cycle_lock);
}
