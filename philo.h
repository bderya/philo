#ifdef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>


typedef struct s_philo
{
	int philo_number;
	int *routine;
	int flag;
	pthread_t thread;
}				t_philo;

#endif