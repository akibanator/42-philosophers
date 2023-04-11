#ifndef PHILO_H
# define PHILO_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<sys/time.h>

typedef struct s_philo {
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int	current_time;
} t_philo;

size_t	ft_strlen(const char *str);
long	ft_atol(const char *nptr);
int		ft_isdigit(int c);

#endif
