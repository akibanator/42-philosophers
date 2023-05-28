/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:49:23 by akenji-a          #+#    #+#             */
/*   Updated: 2023/05/27 20:55:09 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	is_valid_number(int argc, char *argv[])
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (i < argc)
	{
		while (argv[i][y])
		{
			if (argv[i][y] == '-')
				return (1);
			else if (ft_isdigit(argv[i][y]))
				y++;
			else
				return (1);
		}
		y = 0;
		i++;
	}
	return (0);
}

static void	parse_args(char *argv[], t_args *args, int i)
{
	long	num;

	while (*(++argv) != NULL)
	{
		num = ft_atol(*argv);
		if (num > MAX_INT)
		{
			printf("Arguments must be integer.\n");
			free(args);
			exit(0);
		}
		if (i == 0 && num > 0)
			args->number_of_philosophers = num;
		else if (i == 1)
			args->time_to_die = num;
		else if (i == 2)
			args->time_to_eat = num;
		else if (i == 3)
			args->time_to_sleep = num;
		else if (i == 4)
				args->number_of_times_each_philosopher_must_eat = num;
		i++;
	}
	if (i == 4)
		args->number_of_times_each_philosopher_must_eat = -1;
}

t_args	*setup_args(char *argv[])
{
	t_args		*args;

	args = malloc(sizeof(t_args));
	if (args == NULL)
		exit(0);
	parse_args(argv, args, 0);
	args->print_lock = malloc(sizeof(pthread_mutex_t) * 1);
	if (args->print_lock == NULL)
		return (NULL);
	args->stop_lock = malloc(sizeof(pthread_mutex_t) * 1);
	if (args->stop_lock == NULL)
		return (NULL);
	pthread_mutex_init(args->print_lock, NULL);
	pthread_mutex_init(args->stop_lock, NULL);
	args->is_dead = 0;
	args->start_time = get_current_time();
	return (args);
}
