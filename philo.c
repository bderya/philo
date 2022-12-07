 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:15:06 by bderya            #+#    #+#             */
/*   Updated: 2022/10/26 16:43:50 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_atoi()
{
	printf("");
	
}

void	check_arg(char **argv, int argc, int flag)
{
	int i;
	int checker;

	i = 1;
	checker = 0;
	while (i < argc)
	{
		checker = atoi(argv[i]);
		if (checker == 0)
		{
			error_atoi();
			flag = 1;
		}
	}
}

time_t get_time_in_ms(void)
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	error_argv()
{
		printf("Please enter :\n");
		printf("./philo Philo_number time_to_die time_to_sleep\n");
		printf("---------------or---------------\n");
		printf("./philo Philo_number time_to_die time_to_sleep ");
		printf("number_times_philo_must_eat\n");
}
void eat_philo()
{
	
}

void sleep_philo(int philoNo,int start_time)
{
	int  time;
	usleep(100*1000);
	time = get_time_in_ms();
	printf("Philo %d, time in = %ld",philoNo,time - start_time);
}

// void init_philo(char **argv, int argc, t_philo *philo)
// {
// 	philo->philo_number = atoi(argv[1]);//atoi libten ekle
// 	int i = 0;
// 	while (i < philo->philo_number)
// 	{
// 		pthread_create(&philo->thread[i], NULL,&philo->routine[i], NULL);
// 	}
// }
static void parsing(t_philo *philo, int argc, char *argv[])
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_of_must_eat = ft_atoi(argv[5]);
}

void init_philo(t_philo *philo, int argc, char *argv[])
{
	parsing(philo, argc, argv);

}
void error_inval()
{
	printf("Your arg invalid\n");
	printf("Program End\n");
}

int	main(int argc, char **argv)
{
	t_philo philo;
	
	memset(&philo, 0, sizeof(philo));
	if (argc == 5 || argc == 6)
	{
		philo.flag = 0;
		check_arg(argv,argc,&philo.flag);
		if (philo.flag == 1)
			return(error_inval());
		if(init_philo(argv,argc, &philo))
			return(printf("Inital problem"));
		create_philo(&philo);
		join_free_philo(&philo);
	}
	else
	{
		error_argv();
	}
	return (0);
}
