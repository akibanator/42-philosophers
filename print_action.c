/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:56:00 by akenji-a          #+#    #+#             */
/*   Updated: 2023/05/26 14:37:21 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	print_action(t_philo *philo, int status)
{
	unsigned int	execution_time;

	execution_time = timer(philo->args->start_time);
	pthread_mutex_lock(philo->args->print_lock);
	if (status == FORK)
		printf("%ums philo %d has taken a fork\n", execution_time, philo->id);
	else if (status == EAT)
		printf("%ums philo %d is eating\n", execution_time, philo->id);
	else if (status == SLEEP)
		printf("%ums philo %d is sleeping\n", execution_time, philo->id);
	else if (status == THINK)
		printf("%ums philo %d is thinking\n", execution_time, philo->id);
	else if (status == DIE)
		printf("%ums philo %d died\n", execution_time, philo->id);
	pthread_mutex_unlock(philo->args->print_lock);
}
