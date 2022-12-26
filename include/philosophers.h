/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:15:06 by bderya            #+#    #+#             */
/*   Updated: 2022/12/26 22:35:02 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*
HEADER
*/
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

# define FALSE	0
# define TRUE	1

typedef struct s_data	t_data;
typedef struct s_philo		t_philo;

/*
Philo 
*/
typedef struct s_philo
{
	pthread_t	tid;
	int			id;
	int			meals_eaten;
	long long	t_lastmeal;
	int			l_fork;
	int			r_fork;
	t_data	*args;
}	t_philo;

/*
Philo info
*/
typedef struct s_data
{
	int				number_of_philo;
	long long		t0;
	long long		time_to_die;
	long long		t_to_eat;
	long long		t_to_sleep;
	int				max_meals;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	cout;
	pthread_mutex_t	checker;
	int				error;
	int				end_meal;
	int				game_over;
}	t_data;

/* 
	init.c 
*/
int			check_argv(int argc, char **argv);
void		init_data(char **argv, t_data *input);
void		init_philo(t_data *input);

/* 
	timeutils.c 
*/
long long	start_time(void);
long long	timestamp(t_data *input);
void		ft_sleep(t_philo *p, int t_wait);

/* 
	utils.c 
*/
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t num, size_t size);
void		print(t_philo *philo, char *state);

/* 
	control.c 
*/
void		*one_philo(void *p);
void		philo_start(t_data *input);
void		*philo_do(void *p);
void		philo_end(t_data *input);
void		checker(t_data *c);
void		check_death(t_philo *p);

/* 
	philo_bev.c 
*/
void		philo_eat(t_philo *ph);
void		philo_think(t_philo *ph);
void		philo_sleep(t_philo *ph);

#endif
