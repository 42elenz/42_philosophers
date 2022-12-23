/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:34:50 by elenz             #+#    #+#             */
/*   Updated: 2021/12/03 17:34:57 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	start(t_frame frame)
{
	if (phil2table(frame) != 0)
		ft_error(NULL, &frame);
	ft_free_end(&frame);
}

int	main(int argc, char **argv)
{
	t_temp	temp;
	t_frame	frame;
	int		*argv_i;

	temp = init_temp(argc, argv);
	temp.argc = ft_getsize(temp);
	argv_i = str_to_int(&temp, argc);
	if (temp.argc < 4 || temp.argc > 5)
		ft_error(NULL, NULL);
	get_params(argv_i, &frame);
	start(frame);
	free(argv_i);
	exit(0);
}
