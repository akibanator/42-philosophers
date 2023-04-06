#include	"philo.h"

static int	is_valid_number(int argc, char *argv[])
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
				y++;
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

static int	check_args(int argc, char *argv[], t_philo **philo)
{
	long		num;

	*philo = malloc(sizeof(t_philo));
	if (*philo == NULL)
		return (1);
	argc = 0;
	while (*(++argv) != NULL)
	{
		num = ft_atol(*argv);
		if (num < -2147483648 || num > 2147483647)
			return (1);
		if (argc == 0)
			(*philo)->number_of_philosophers = num;
		else if (argc == 1)
			(*philo)->time_to_die = num;
		else if (argc == 2)
			(*philo)->time_to_eat = num;
		else if (argc == 3)
			(*philo)->time_to_sleep = num;
		else if (argc == 4)
			(*philo)->number_of_times_each_philosopher_must_eat = num;
		argc++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	t_philo	*philo;
	
	if (argc < 5 || argc > 6)
		return (0);
	if (is_valid_number(argc, argv) || check_args(argc, argv, &philo))
		return (0);

	free(philo);
	return (0);
}

