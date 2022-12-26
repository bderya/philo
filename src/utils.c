/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:15:06 by bderya            #+#    #+#             */
/*   Updated: 2022/12/26 22:35:27 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

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

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
	s = tmp;
}

 /*
Printing philo act
 */
void	print(t_philo *philo, char *state)
{
	if (philo->args->game_over == FALSE)
	{
		pthread_mutex_lock(&philo->args->cout);
		printf("%lld\t%d\t%s\n", timestamp(philo->args), philo->id, state);
		pthread_mutex_unlock(&philo->args->cout);
	}
}
