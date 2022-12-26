/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behaviour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:15:06 by bderya            #+#    #+#             */
/*   Updated: 2022/12/26 22:35:10 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*one_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	pthread_mutex_lock(&philo->args->fork[philo->l_fork]);
	print(philo, "has taken a fork");
	philo->t_lastmeal = timestamp(philo->args);
	ft_sleep(philo, philo->args->time_to_die);
	print(philo, "died");
	philo->args->game_over = TRUE;
	return (NULL);
}

/*

*/
void	philo_eat(t_philo *philo)
{
	if (philo->args->game_over == FALSE)
	{
		pthread_mutex_lock(&philo->args->fork[philo->l_fork]);
		print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->args->fork[philo->r_fork]);
		print(philo, "has taken a fork");
		print(philo, "is eating ");
		philo->t_lastmeal = timestamp(philo->args);
		philo->meals_eaten += 1;
		ft_sleep(philo, philo->args->t_to_eat);
		pthread_mutex_unlock(&philo->args->fork[philo->l_fork]);
		pthread_mutex_unlock(&philo->args->fork[philo->r_fork]);
	}
}

/*
Thinking philo
*/
void	philo_think(t_philo *philo)
{
	if (philo->args->game_over == FALSE)
		print(philo, "is thinking ");
}

void	philo_sleep(t_philo *philo)
{
	if (philo->args->game_over == FALSE)
	{
		print(philo, "is sleeping");
		ft_sleep(philo, philo->args->t_to_sleep);
	}
}
