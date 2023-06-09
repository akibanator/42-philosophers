/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:20:43 by akenji-a          #+#    #+#             */
/*   Updated: 2023/05/27 19:22:47 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r'
		|| c == '\f' || c == '\v')
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	long	num;
	long	sign;

	while ((ft_isspace(*nptr)))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	num = 0;
	while ((ft_isdigit(*nptr)))
	{
		num *= 10;
		num += sign * (*nptr - '0');
		nptr++;
	}
	return (num);
}

int	is_philo_alone(t_philo *philo)
{
	if (philo->left_fork == NULL)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	return (0);
}
