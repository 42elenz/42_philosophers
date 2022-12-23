/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:34:13 by elenz             #+#    #+#             */
/*   Updated: 2021/12/03 17:34:16 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	set_dead(t_philo *philo)
{
	philo->tod = ft_get_time();
	ft_print(philo, 'd');
	return (1);
}

int	look_fork(t_philo *philo, char x)
{
	if (philo->id == 1)
	{
		if (x == 'r')
		{
			return (philo->data->fork_value[philo->data->n_phil - 1]);
		}
		if (x == 'l')
		{
			return (philo->data->fork_value[0]);
		}
	}
	else
	{
		if (x == 'r')
			return (philo->data->fork_value[philo->id - 2]);
		if (x == 'l')
			return (philo->data->fork_value[philo->id - 1]);
	}
	return (0);
}

void	set_fork(t_philo *philo, char x, int v)
{
	if (philo->id == 1)
	{
		if (x == 'r')
			philo->data->fork_value[philo->data->n_phil - 1] = v;
		if (x == 'l')
			philo->data->fork_value[0] = v;
	}
	else
	{
		if (x == 'r')
			philo->data->fork_value[philo->id - 2] = v;
		if (x == 'l')
			philo->data->fork_value[philo->id - 1] = v;
	}
	if (v == 0)
	{
		philo->up_fork = ft_get_time();
		ft_print(philo, 'u');
	}
}
