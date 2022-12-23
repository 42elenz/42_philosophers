/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philtotable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:35:27 by elenz             #+#    #+#             */
/*   Updated: 2021/12/03 17:35:28 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	assign_number(t_philo *philo)
{
	if (philo->data->nte)
		philo->eaten = philo->data->nte;
	pthread_mutex_lock(&philo->data->id_locker);
	philo->data->number += 1;
	philo->id = philo->data->number;
	pthread_mutex_unlock(&philo->data->id_locker);
}

static void	assign_forks(t_philo *philo)
{
	if (philo->id == 1)
	{
		philo->rfork = &philo->data->forks[philo->data->n_phil - 1];
		philo->lfork = &philo->data->forks[0];
	}
	else
	{
		philo->rfork = &philo->data->forks[philo->id - 2];
		philo->lfork = &philo->data->forks[philo->id - 1];
	}
}

static void	prebirth(t_philo *philo)
{
	while (philo->data->counter < philo->data->n_phil - 1)
		usleep(20);
}

static void	*phil_cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	assign_number(philo);
	assign_forks(philo);
	prebirth(philo);
	philo->lastte = ft_get_time();
	if (philo->id % 2 == 0)
	{
		ft_sleep(philo);
		ft_print(philo, 't');
	}
	while (philo->data->dead == 0 && philo->eaten > 0)
	{
		ft_eat(philo);
		if (ft_get_time() - philo->lastte >= (unsigned long long)
			philo->data->ttdie)
			ft_print(philo, 'd');
		if (philo->data->dead == 0 && philo->eaten > 0)
			ft_sleep(philo);
		if (philo->data->dead == 0 && philo->eaten > 0)
			ft_print(philo, 't');
	}
	return (NULL);
}

int	phil2table(t_frame frame)
{
	t_philo	*philos;

	frame.counter = 0;
	philos = malloc(frame.n_phil * sizeof(t_philo));
	if (philos == NULL)
		ft_error(NULL, &frame);
	frame.philo_ar = philos;
	init_forks(&frame);
	frame.start = ft_get_time();
	while (frame.counter < frame.n_phil)
	{
		philos[frame.counter].data = &frame;
		if (pthread_create(&philos[frame.counter].th, NULL,
				&phil_cycle, &philos[frame.counter]) != 0)
			break ;
		frame.counter++;
	}
	frame.n_phil = frame.counter;
	while (frame.counter > 0)
	{
		pthread_join(philos[frame.counter - 1].th, NULL);
		frame.counter--;
	}
	ft_free_philos(philos, &frame);
	return (0);
}
