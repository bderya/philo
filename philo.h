#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>



typedef struct s_data
{
	int number_of_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_of_must_eat; // kontrol et pthread ve mutex olarak bak
	pthread_t righ_fork;
	pthread_t left_fork;
	pthread_t *number;
}		t_philo;


#endif