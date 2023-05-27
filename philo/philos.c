/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:07:30 by akenji-a          #+#    #+#             */
/*   Updated: 2023/05/27 17:45:35 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static t_philo	setup_philo(t_args *args, pthread_mutex_t **forks, int i)
{
	t_philo	philo;

	philo.id = i + 1;
	philo.meals_count = args->number_of_times_each_philosopher_must_eat;
	philo.last_meal_time = get_current_time();
	philo.meal_lock = malloc(sizeof(pthread_mutex_t) * 1);
	pthread_mutex_init(philo.meal_lock, NULL);
	if (i == 0)
	{
		philo.right_fork = forks[0];
		if (args->number_of_philosophers == 1)
			philo.left_fork = NULL;
		else
			philo.left_fork = forks[args->number_of_philosophers - 1];
	}
	else
	{
		philo.right_fork = forks[i];
		philo.left_fork = forks[i - 1];
	}
	philo.args = args;
	return (philo);
}

t_philo	*init_philos(t_args *args, pthread_mutex_t **forks)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * args->number_of_philosophers);
	if (philos == NULL)
		return (NULL);
	while (i < args->number_of_philosophers)
	{
		philos[i] = setup_philo(args, forks, i);
		i++;
	}
	return (philos);
}
