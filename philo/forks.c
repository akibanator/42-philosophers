/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:41:19 by akenji-a          #+#    #+#             */
/*   Updated: 2023/05/26 05:45:19 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

pthread_mutex_t	**init_forks(int philos)
{
	pthread_mutex_t	**forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * philos);
	if (forks == NULL)
		return (NULL);
	i = 0;
	while (i < philos)
	{
		forks[i] = malloc(sizeof(pthread_mutex_t));
		if (forks[i] == NULL)
			return (NULL);
		pthread_mutex_init(forks[i], NULL);
		i++;
	}
	return (forks);
}

void	free_forks(pthread_mutex_t **forks, int philos)
{
	int	i;

	i = 0;
	while (i < philos)
	{
		pthread_mutex_destroy(forks[i]);
		free(forks[i]);
		i++;
	}
	free(forks);
}
