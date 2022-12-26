/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:15:06 by bderya            #+#    #+#             */
/*   Updated: 2022/12/26 22:34:45 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
The main for start program
Chec_argv = Checks the entered values
init_data = initialization the entered values
philo_start = starting program
philo_end = ending program
*/
int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_argv(argc, argv) != 0)
		return (-1);
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (-1);
	init_data(argv, data);
	philo_start(data);
	philo_end(data);
	return (0);
}
