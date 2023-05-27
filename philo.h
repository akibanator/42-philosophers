/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:08:04 by akenji-a          #+#    #+#             */
/*   Updated: 2023/05/27 17:24:56 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<sys/time.h>
# include	<pthread.h>
# include	<unistd.h>

# define MAX_INT 2147483647
# define FORK 2
# define EAT 3
# define SLEEP 4
# define THINK 5
# define DIE 6

typedef struct s_args {
	int				number_of_philosophers;
	unsigned int	time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	unsigned int	start_time;
	int				is_dead;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*stop_lock;
}	t_args;

typedef struct s_philo {
	int					id;
	unsigned int		last_meal_time;
	int					meals_count;
	pthread_mutex_t		*meal_lock;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	t_args				*args;
}	t_philo;

long			ft_atol(const char *nptr);
int				ft_isdigit(int c);
int				is_valid_number(int argc, char *argv[]);
t_args			*setup_args(char *argv[]);
unsigned int	get_current_time(void);
unsigned int	timer(unsigned int start_time);
pthread_mutex_t	**init_forks(int philos);
void			free_forks(pthread_mutex_t **forks, int philos);
t_philo			*init_philos(t_args *args, pthread_mutex_t **forks);
void			free_all(t_args *args, t_philo *philos);
void			run_meal(t_philo *philos, t_args *args);
int				eating(t_philo *philo);
void			print_action(t_philo *philo, int status);
int				sleeping(t_philo *philo);
int				thinking(t_philo *philo);
unsigned int	get_delta_time(unsigned int last_meal_time);

#endif
