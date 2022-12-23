/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readparams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:35:34 by elenz             #+#    #+#             */
/*   Updated: 2021/12/03 17:35:35 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	get_params(int *argv_i, t_frame *frame)
{
	frame->n_phil = argv_i[0];
	frame->ttdie = argv_i[1];
	frame->tte = argv_i[2];
	frame->tts = argv_i[3];
	frame->number = 0;
	frame->dead = 0;
	frame->fed = 0;
	frame->counter = 0;
	if (pthread_mutex_init(&frame->print_locker, NULL) != 0)
		ft_error(NULL, frame);
	if (pthread_mutex_init(&frame->id_locker, NULL) != 0)
		ft_error(NULL, frame);
	if (argv_i[4])
		frame->nte = argv_i[4];
	else
		frame->nte = INT_MAX;
}
