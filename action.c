/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:20:07 by akenji-a          #+#    #+#             */
/*   Updated: 2023/05/27 17:22:32 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int		check_death(t_philo *philo)
{
	pthread_mutex_lock(philo->args->stop_lock);
	if (philo->args->is_dead == 1)
	{
		pthread_mutex_unlock(philo->args->stop_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->args->stop_lock);
	return (0);
}

void	update_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = get_current_time();
	philo->meals_count--;
	pthread_mutex_unlock(philo->meal_lock);
}

int	eating(t_philo *philo)
{
	if (check_death(philo))
		return (1);
	pthread_mutex_lock(philo->right_fork);
	if (check_death(philo))
		return (1);
	print_action(philo, FORK);
	pthread_mutex_lock(philo->left_fork);
	if (check_death(philo))
		return (1);
	print_action(philo, FORK);
	print_action(philo, EAT);
	update_philo(philo);
	usleep(philo->args->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (check_death(philo))
		return (1);
	print_action(philo, SLEEP);
	usleep(philo->args->time_to_sleep * 1000);
	if (check_death(philo))
		return (1);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (check_death(philo))
		return (1);
	print_action(philo, THINK);
	return (0);
}
