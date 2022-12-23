/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:34:21 by elenz             #+#    #+#             */
/*   Updated: 2021/12/03 17:34:23 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free (split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

void	ft_error(int *int_ret, t_frame *frame)
{
	int	i;

	i = 0;
	if (int_ret != NULL)
		free(int_ret);
	if (frame != NULL)
	{
		if (frame->forks)
			free(frame->forks);
		if (frame->fork_value)
			free(frame->fork_value);
		if (frame->philo_ar)
			free(frame->philo_ar);
		free(frame);
	}
	write(2, "ERROR\n", 5);
	exit(0);
}

void	ft_free_end(t_frame *frame)
{
	pthread_mutex_destroy(&frame->print_locker);
	pthread_mutex_destroy(&frame->id_locker);
}

void	ft_free_philos(t_philo *philos, t_frame *frame)
{
	int	i;

	i = 0;
	while (i < frame->n_phil)
	{
		pthread_mutex_destroy(&frame->forks[i]);
		i++;
	}
	free(frame->fork_value);
	free(philos);
	free(frame->forks);
}

void	locker(t_philo *philo)
{
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_lock(philo->lfork);
}
