/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:51:13 by akenji-a          #+#    #+#             */
/*   Updated: 2023/05/27 17:29:40 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	free_all(t_args *args, t_philo *philos)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(args->print_lock);
	pthread_mutex_destroy(args->stop_lock);
	free(args->print_lock);
	free(args->stop_lock);
	free(args);
	while (i < philos->args->number_of_philosophers)
	{
		pthread_mutex_destroy(philos[i].meal_lock);
		free(philos[i].meal_lock);
	}
	free(philos);
}
