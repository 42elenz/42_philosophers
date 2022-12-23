/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philfct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:35:16 by elenz             #+#    #+#             */
/*   Updated: 2021/12/03 17:35:18 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_eat2(t_philo *philo, int *has_l, int *has_r)
{
	*has_l = 0;
	*has_r = 0;
	philo->lastte = ft_get_time();
	ft_print(philo, 'e');
	philo->eaten--;
	ft_usleep(philo->data->tte, philo);
	pthread_mutex_lock(philo->lfork);
	philo->down_fork = ft_get_time();
	set_fork(philo, 'l', 1);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_lock(philo->rfork);
	philo->down_fork = ft_get_time();
	set_fork(philo, 'r', 1);
	pthread_mutex_unlock(philo->rfork);
}

static void	set_r_fork(int *has_r, t_philo *philo)
{
	*has_r = 1;
	set_fork(philo, 'r', 0);
}

static void	set_l_fork(int *has_l, t_philo *philo)
{
	*has_l = 1;
	set_fork(philo, 'l', 0);
}

void	ft_eat(t_philo *philo)
{
	int	has_l;
	int	has_r;

	has_l = 0;
	has_r = 0;
	while (1)
	{
		if (ft_get_time() - philo->lastte >= (unsigned long long)
			philo->data->ttdie)
			if (set_dead(philo) == 1)
				break ;
		pthread_mutex_lock(philo->rfork);
		if (look_fork(philo, 'r') == 1)
			set_r_fork(&has_r, philo);
		locker(philo);
		if (look_fork(philo, 'l') == 1)
			set_l_fork(&has_l, philo);
		pthread_mutex_unlock(philo->lfork);
		if (has_r && has_l)
		{
			ft_eat2(philo, &has_l, &has_r);
			break ;
		}
		usleep(100);
	}
}

void	ft_sleep(t_philo *philo)
{
	philo->s_now = ft_get_time();
	ft_print(philo, 's');
	ft_usleep(philo->data->tts, philo);
}
