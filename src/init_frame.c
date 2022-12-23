/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:34:37 by elenz             #+#    #+#             */
/*   Updated: 2021/12/03 17:34:38 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_forks(t_frame *frame)
{
	int	i;

	i = 0;
	frame->forks = malloc(frame->n_phil * sizeof(pthread_mutex_t));
	if (frame->forks == NULL)
		ft_error(NULL, frame);
	frame->fork_value = malloc(frame->n_phil * sizeof(int));
	if (frame->fork_value == NULL)
		ft_error(NULL, frame);
	while (i < frame->n_phil)
	{
		pthread_mutex_init(&frame->forks[i], NULL);
		frame->fork_value[i] = 1;
		i++;
	}
	return (0);
}

t_temp	init_temp(int argc, char **argv)
{
	t_temp	temp;

	temp.argc = argc;
	temp.argv = argv;
	return (temp);
}
