/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:56:01 by akenji-a          #+#    #+#             */
/*   Updated: 2023/05/27 16:28:40 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

unsigned int	get_current_time(void)
{
	struct timeval	time;
	unsigned int	time_in_ms;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("Error in get_current_time function\n");
		exit(0);
	}
	time_in_ms = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (time_in_ms);
}

unsigned int	timer(unsigned int start_time)
{
	unsigned int	current_time;

	current_time = get_current_time();
	return (current_time - start_time);
}

unsigned int	get_delta_time(unsigned int last_meal_time)
{
	return (get_current_time() - last_meal_time);
}
