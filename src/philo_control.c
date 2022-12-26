/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:15:06 by bderya            #+#    #+#             */
/*   Updated: 2022/12/26 22:34:36 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
Philo Start
*/
void	philo_start(t_data *data)
{
	int		i;

	if (data->number_of_philo == 1)
	{
		one_philo(data->philo);
	}
	else
	{
		i = 0;
		while (i < data->number_of_philo)
		{
			pthread_create(&data->philo[i].tid, NULL, \
			&philo_do, (void *) &data->philo[i]);
			i++;
		}
		while (data->game_over == FALSE)
			checker(data);
	}
}

/*
The program decides what Philo will do
*/
void	*philo_do(void *p)
{
	t_philo		*philo;
	t_data	*data;

	philo = (t_philo *)p;
	data = philo->args;
	if (philo->id % 2)
		usleep(1500);
	while (data->game_over == FALSE)
	{
		if (data->max_meals > 0 && philo->meals_eaten == data->max_meals)
			break ;
		philo_eat(philo);
		philo_think(philo);
		philo_sleep(philo);
	}
	return (NULL);
}

/*
Controlling philo time
*/
void	checker(t_data *data)
{
	int	meal_i;
	int	death_i;

	meal_i = 0;
	death_i = 0;
	while (data->game_over == FALSE)
	{
		check_death(&data->philo[death_i]);
		if (data->max_meals > 0)
		{
			while (meal_i < data->number_of_philo)
			{
				if (data->philo[meal_i].meals_eaten < data->max_meals)
					break ;
				meal_i++;
			}
			if (meal_i == data->number_of_philo)
				data->game_over = TRUE;
		}
		usleep(5000);
		if (death_i == data->number_of_philo -1)
			death_i = -1;
		death_i++;
	}
}

void	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->checker);
	if ((timestamp(philo->args) - philo->t_lastmeal) >= philo->args->time_to_die)
	{
		print(philo, "died \xF0\x9F\x92\x80");
		philo->args->game_over = TRUE;
	}
	pthread_mutex_unlock(&philo->args->checker);
}

void	philo_end(t_data *data)
{
	int	i;

	i = data->number_of_philo;
	while (--i >= 0)
		pthread_join(data->philo[i].tid, NULL);
	while (++i < data->number_of_philo)
		pthread_mutex_destroy(&data->fork[i]);
	pthread_mutex_destroy(&data->cout);
	pthread_mutex_destroy(&data->checker);
	free(data->philo);
	free(data->fork);
	free(data);
}
