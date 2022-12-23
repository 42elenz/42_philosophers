/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:34:44 by elenz             #+#    #+#             */
/*   Updated: 2021/12/03 17:34:45 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_atoi(char *str, int *int_ret)
{
	int		i;
	int		neg;
	long	re;

	neg = 1;
	i = 0;
	re = 0;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		re = re * 10 + (str[i] - '0');
		if (re > 2147483647 || re < 0)
			ft_error(int_ret, NULL);
		i++;
	}
	if ((re * neg) < 0)
		ft_error(int_ret, NULL);
	return (re * neg);
}

int	ft_getsize(t_temp temp)
{
	char	**arr;
	int		i;
	int		j;
	int		argcount;

	i = 1;
	argcount = 0;
	while (i < temp.argc)
	{
		arr = ft_split(temp.argv[i], ' ');
		i++;
		j = 0;
		while (arr[j])
		{
			argcount++;
			j++;
		}
		ft_free_split(arr);
	}
	return (argcount);
}

static void	input_checker(char *arr, int *int_ret)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_isdigit(arr[i]) == 0)
			ft_error(int_ret, NULL);
		i++;
	}
}

int	*str_to_int(t_temp	*temp, int argc)
{
	char	**arr;
	int		*int_ret;
	int		i;
	int		j;
	int		p;

	i = 1;
	p = 0;
	int_ret = malloc(temp->argc * sizeof(int));
	while (i < argc)
	{
		arr = ft_split((*temp).argv[i], ' ');
		i++;
		j = 0;
		while (arr[j])
		{
			input_checker(arr[j], int_ret);
			int_ret[p] = ft_atoi(arr[j], int_ret);
			j++;
			p++;
		}
		ft_free_split(arr);
	}
	return (int_ret);
}
