/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:18:40 by ade-ross          #+#    #+#             */
/*   Updated: 2025/03/26 19:26:39 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <pthread.h>
#include <unistd.h>
//non so se si possono includere ma credo di si
#include <sys/time.h>
#include <time.h>
#include <stdbool.h>
//da levare di sicuro
#include <stdio.h>
#include <stdlib.h>

struct	s_philo;

typedef struct s_data
{
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	cycle_lock;
	pthread_mutex_t	position_lock;
	pthread_mutex_t	iseven_lock;
	pthread_mutex_t	printf_lock;
	int				position[202];
	int				is_even;
	int				n_phils;
	int				ttd;
	int				tte;
	int				tts;
	int				cycles;
	int				cur_cycle[202];
	long int		started_eating;
	long int		last_started_eating[202];
	int				is_dead;
}					t_data;

typedef struct s_philo
{
	pthread_mutex_t	fork;
	t_data			*all;
	struct s_philo	*prev;
}					t_philo;

typedef struct s_allphilos
{
	pthread_t	thread_ids[202];
	t_philo		philos[202];
}				t_allphilos;

//long int	get_time_m(void);
long int	get_time(void);

int			check_input(char **argv, int argc);

int			ft_atoi(const char *nptr);

void		initialize_started_eating_time(t_data *all);
void		initialize_positions(t_data *all);
int			initialize_all(t_data *all, char **argv, int argc);

void		try_sec_fork_even(t_data *all, t_philo *philo, int ph_n);
void		try_sec_fork_odd(t_data *all, t_philo *philo, int ph_n);
void		try_first_fork_even(t_data *all, t_philo *philo, int i);
void		try_first_fork_odd(t_data *all, t_philo *philo, int i);

int			try_to_eat_even(t_data *all, t_philo *philo, int i);
int			try_to_eat_odd(t_data *all, t_philo *philo, int i);
int			try_to_eat(t_data *all, t_philo *philo, int i);

void		dumb_initialize(t_data *all, int i, t_allphilos *phs);
int			check_is_dead(t_data *all);
int			philosopher_h(void *all, t_philo *philo, int ph_n);
void		initialize_i(int *i, void *all);
void		*philosopher(void *all);

int			check_phil_is_dead(void *all, int i);
void		stupid_ft(void *all);
void		*check_phs_are_alive(void *all);
