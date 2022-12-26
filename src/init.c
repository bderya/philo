/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:15:06 by bderya            #+#    #+#             */
/*   Updated: 2022/12/26 22:34:52 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
Argument control. Function controlling of number of philo,eat,die,sleep,must eat. if bigger dan INT_MAX
or smaller than 0, programs end
*/
int	check_argv(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("Command Error. Please follow instruction\n");
		return (-1);
	}
	i = 0;
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) <= 0 || ft_atoi(argv[i]) > INT_MAX)
		{
			printf("Argument Error. Please enter bigger than 0 and smaller than INT_MAX\n");
			return (-1);
		}
	}
	return (0);
}

/*
Starting the philosopher and integrating program values ​​into the system
Initalizion of data for philo

time_to_die = Die time for philo
time_to_eat = Meal time for philo
time_to_slepp = Die for philo
*/
void	init_data(char **argv, t_data *data)
{
	int	i;

	i = -1;
	data->error = FALSE;
	data->game_over = FALSE;
	data->end_meal = 0;
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->t_to_eat = ft_atoi(argv[3]);
	data->t_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->max_meals = ft_atoi(argv[5]);
	else
		data->max_meals = FALSE;
	data->philo = ft_calloc(data->number_of_philo, (sizeof(t_philo)));
	data->fork = ft_calloc(data->number_of_philo, (sizeof(pthread_mutex_t)));
	pthread_mutex_init(&data->cout, NULL);
	pthread_mutex_init(&data->checker, NULL);
	while (++i < data->number_of_philo)
		pthread_mutex_init(&data->fork[i], NULL);
	init_philo(data);
	data->t0 = start_time();
}

/*
The struct contains the id of the philosopher, 
The id of the right and left fork, and the struct of the simulation.
The function allocates memory for the struct and then initializes it
*/
void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].meals_eaten = 0;
		data->philo[i].t_lastmeal = 0;
		data->philo[i].l_fork = i;
		data->philo[i].r_fork = (i + 1) % data->number_of_philo;
		data->philo[i].args = data;
		i++;
	}
}
