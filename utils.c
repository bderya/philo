#include "philo.h"

void	error_argv()
{
		printf("Please enter :\n");
		printf("./philo Philo_number time_to_die time_to_sleep\n");
		printf("---------------or---------------\n");
		printf("./philo Philo_number time_to_die time_to_sleep ");
		printf("number_times_philo_must_eat\n");
}

void error_inval()
{
	printf("Your arg invalid\n");
	printf("Program End\n");
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
	{
		i++;
	}
	if ('+' == str[i] || '-' == str[i])
	{
		if ('-' == str[i])
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && '9' >= str[i])
	{
		res = res * 10 + ((str[i] - '0'));
		i++;
	}
	return (sign * (res));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}