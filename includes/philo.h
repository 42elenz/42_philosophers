/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:36:09 by elenz             #+#    #+#             */
/*   Updated: 2021/12/03 17:36:10 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

struct	s_philo;

typedef struct temp
{
	int		argc;
	char	**argv;
}	t_temp;

typedef struct frame
{
	int					n_phil;
	int					number;
	int					ttdie;
	int					tte;
	int					tts;
	int					nte;
	int					dead;
	int					fed;
	pthread_mutex_t		print_locker;
	pthread_mutex_t		id_locker;
	pthread_mutex_t		*forks;
	int					*fork_value;
	unsigned long long	start;
	struct s_philo		*philo_ar;
	int					counter;
}	t_frame;

typedef struct s_philo
{
	t_frame				*data;
	pthread_t			th;
	int					id;
	unsigned long long	s_now;
	int					eaten;
	void				*lfork;
	void				*rfork;
	unsigned long long	tod;
	unsigned long long	lastte;
	unsigned long long	up_fork;
	unsigned long long	down_fork;
}	t_philo;

typedef struct time
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
}	t_time;

/*
** FUNCTIONS TO INIT AND PREPARE THE INPUT
*/

t_temp				init_temp(int argc, char **argv);
int					ft_getsize(t_temp temp);
char				**ft_split(char const *s, char c);
void				init_frame(char **argv);
int					*str_to_int(t_temp *temp, int argc);
int					ft_isdigit(int c);
void				get_params(int *argv_i, t_frame *frame);

/*
** PHILO FUNCTIONS
*/

int					phil2table(t_frame frame);
int					init_forks(t_frame *frame);
int					look_fork(t_philo *philo, char x);
void				set_fork(t_philo *philo, char x, int v);
void				ft_eat(t_philo *philo);
int					ft_usleep(int time, t_philo *philo);
void				ft_sleep(t_philo *philo);
unsigned long long	ft_get_time(void);
void				locker(t_philo *philo);
int					set_dead(t_philo *philo);
void				ft_print(t_philo *philo, char p);

/*
** ERROR AND FREE FUNCTIONS
*/

void				ft_error(int *int_ret, t_frame *frame);
void				ft_free_split(char **split);
void				ft_free_end(t_frame *frame);
void				ft_free_philos(t_philo *philos, t_frame *frame);

#endif