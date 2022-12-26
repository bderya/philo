/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:15:06 by bderya            #+#    #+#             */
/*   Updated: 2022/12/26 22:35:21 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
Time starter for philo
*/
long long	start_time(void)
{
	struct timeval	t0;

	gettimeofday(&t0, NULL);
	return ((t0.tv_sec * 1000) + (t0.tv_usec / 1000));
}

/*
Taking current time
*/
long long	timestamp(t_data *input)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (((current.tv_sec * 1000) + (current.tv_usec / 1000)) - input->t0);
}

void	ft_sleep(t_philo *p, int t_wait)
{
	long long	time_now;
	long long	diff;

	time_now = timestamp(p->args);
	while (1)
	{
		diff = (timestamp(p->args) - time_now);
		if (diff >= t_wait)
			break ;
		usleep(1000);
	}
}
