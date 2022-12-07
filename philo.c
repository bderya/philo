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

// void	error_atoi()
// {
// 	printf("");
	
// }

// void	check_arg(char **argv, int argc, int flag)
// {
// 	int i;
// 	int checker;

// 	i = 1;
// 	checker = 0;
// 	while (i < argc)
// 	{
// 		checker = atoi(argv[i]);
// 		if (checker == 0)
// 		{
// 			error_atoi();
// 			flag = 1;
// 		}
// 	}
// }

// time_t get_time_in_ms(void)
// {
// 	struct timeval tv;
	
// 	gettimeofday(&tv, NULL);
// 	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
// }


// void eat_philo()
// {
	
// }

// void sleep_philo(int philoNo,int start_time)
// {
// 	int  time;
// 	usleep(100*1000);
// 	time = get_time_in_ms();
// 	printf("Philo %d, time in = %ld",philoNo,time - start_time);
// }

// void init_philo(char **argv, int argc, t_philo *philo)
// {
// 	philo->philo_number = atoi(argv[1]);//atoi libten ekle
// 	int i = 0;
// 	while (i < philo->philo_number)
// 	{
// 		pthread_create(&philo->thread[i], NULL,&philo->routine[i], NULL);
// 	}
// }

static void parsing(t_philo *info, int argc, char **argv)
{
	info->number_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_of_must_eat = ft_atoi(argv[5]);
}

void create_philo(t_philo *philo)
{
	int i;

	i = 0;
	while(i < philo->number_of_philo)
	{
		pthread_create(&philo->number[i], NULL,);
	}
}

void init_data(t_philo *philo, int argc, char *argv[])
{
	parsing(philo, argc, argv);
	create_philo(philo);

}

// int	main(int argc, char **argv)
// {
// 	t_philo philo;
	
// 	memset(&philo, 0, sizeof(philo));
// 	if (argc == 5 || argc == 6)
// 	{
// 		philo.flag = 0;
// 		check_arg(argv,argc,&philo.flag);
// 		if (philo.flag == 1)
// 			return(error_inval());
// 		if(init_philo(argv,argc, &philo))
// 			return(printf("Inital problem"));
// 		create_philo(&philo);
// 		join_free_philo(&philo);
// 	}
// 	else
// 	{
// 		error_argv();
// 	}
// 	return (0);
// }

static int check_arg(int argc, char **argv)
{
	int i;

	if (argc < 5 || argc > 6)
	{
		error_argv();
		return (1);
	}
	i = 1;
	while ( i <= argc)
	{
		if((ft_isdigit(argv[i]) || ft_atoi(argv[i])) == 1)
			return (1);
		i++;
	}
	return (0);
}


int main (int argc, char **argv)
{
	t_philo info;

	if (check_arg(argc, argc) == 1)
		return (1);
	init_data(&info, argc, argv);

}