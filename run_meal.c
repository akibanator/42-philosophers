/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_meal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 05:05:10 by akenji-a          #+#    #+#             */
/*   Updated: 2023/05/27 17:21:30 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	*run_waiter(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->meals_count != 0)
	{
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
	return (NULL);
}

void	free_threads(pthread_t *threads, int nb_philos)
{
	int	i;

	i = 0;
	while (i < nb_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
}

int	check_corpse(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->args->number_of_philosophers)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (get_delta_time(philos[i].last_meal_time) >= philos[i].args->time_to_die)
		{
			pthread_mutex_lock(philos[i].args->stop_lock);
			philos->args->is_dead = 1;
			pthread_mutex_unlock(philos[i].args->stop_lock);
			print_action(&philos[i], DIE);
			pthread_mutex_unlock(philos[i].meal_lock);
			return (1);
		}
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	return (0);
}

int	check_end_meal(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->args->number_of_philosophers)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_count != 0)
		{
			pthread_mutex_unlock(philos[i].meal_lock);
			return (0);
		}
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	return (1);
}

void	run_meal(t_philo *philos, t_args *args)
{
	int			i;
	pthread_t	*threads;

	i = 0;
	threads = malloc(sizeof(pthread_t) * args->number_of_philosophers);
	if (threads == NULL)
		return ;
	while (i < args->number_of_philosophers)
	{
		pthread_create(&threads[i], NULL, (void *)&run_waiter, &philos[i]);
		i++;
	}
	while (args->is_dead != 1)
	{
		if (check_corpse(philos))
			break ;
		if (check_end_meal(philos))
			break ;
	}
	free_threads(threads, args->number_of_philosophers);
}
