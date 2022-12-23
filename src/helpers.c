/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:34:29 by elenz             #+#    #+#             */
/*   Updated: 2021/12/03 17:34:31 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (c);
	}
	return (0);
}

unsigned long long	ft_get_time(void)
{
	struct timeval		t;
	unsigned long long	time;

	gettimeofday(&t, NULL);
	time = t.tv_sec * 1000;
	time += t.tv_usec / 1000;
	return (time);
}

int	ft_usleep(int time, t_philo *philo)
{
	unsigned long long	start;

	start = ft_get_time();
	if (philo->eaten == 0)
		ft_print(philo, 'f');
	while ((ft_get_time() - start) < (unsigned long long) time
		&& philo->data->dead == 0)
	{
		if (philo->data->n_phil > 50)
			usleep(100);
		else
			usleep(50);
		if (ft_get_time() - philo->lastte >= (unsigned long long)
			philo->data->ttdie || philo->data->dead == 1)
		{
			philo->tod = ft_get_time();
			ft_print(philo, 'd');
			break ;
		}
	}
	return (0);
}

static void	ft_print2(t_philo *philo, char p, unsigned long long s)
{
	if (p == 'd')
	{
		printf("%llums philo %i died\n", philo->tod - s, philo->id);
		philo->data->dead = 1;
	}
	if (p == 'f')
		printf("%llums all philos fed\n", ft_get_time() - s);
	if (p == 's')
		printf("%llums philo %i is sleeping\n", philo->s_now - s, philo->id);
	if (p == 'e')
		printf("%llums philo %i is eating\n", philo->lastte - s, philo->id);
	if (p == 'u')
		printf("%llums philo %i has taken a fork\n",
			philo->up_fork - s, philo->id);
	if (p == 't')
		printf("%llums philo %i is thinking\n",
			ft_get_time() - s, philo->id);
}

void	ft_print(t_philo *philo, char p)
{
	unsigned long long	s;

	pthread_mutex_lock(&philo->data->print_locker);
	s = philo->data->start;
	if (philo->data->dead == 0 && philo->eaten > 0)
		ft_print2(philo, p, s);
	pthread_mutex_unlock(&philo->data->print_locker);
}
