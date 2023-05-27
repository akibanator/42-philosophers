/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:58:18 by akenji-a          #+#    #+#             */
/*   Updated: 2023/05/27 17:24:40 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	main(int argc, char *argv[])
{
	t_args			*args;
	t_philo			*philos;
	pthread_mutex_t	**forks;

	if (argc < 5 || argc > 6)
	{
		printf("To run the program: ./philo n1 n2 n3 n4 n5(optional)\n");
		return (0);
	}
	if (is_valid_number(argc, argv))
	{
		printf("All the arguments must be positive integer numbers\n");
		return (0);
	}
	args = setup_args(argv);
	forks = init_forks(args->number_of_philosophers);
	philos = init_philos(args, forks);
	run_meal(philos, args);
	free_forks(forks, args->number_of_philosophers);
	free_all(args, philos);
	return (0);
}
