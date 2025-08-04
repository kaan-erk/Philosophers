/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:56:07 by ktoraman          #+#    #+#             */
/*   Updated: 2025/08/04 20:24:07 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	digit_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	table_error(char **av)
{
	if (digit_check(av))
		return (ft_putendl_fd("Non decimal Character in args", 2), 1);
	if (!(ft_atoll(av[1]) < INT_MAX && ft_atoll(av[1]) > 0))
		return (ft_putendl_fd("Invalid integer for number of philosophers", 2),
			1);
	if (!(ft_atoll(av[2]) < INT_MAX && ft_atoll(av[2]) > -1))
		return (ft_putendl_fd("Invalid integer for time to die", 2), 1);
	if (!(ft_atoll(av[3]) < INT_MAX && ft_atoll(av[3]) > -1))
		return (ft_putendl_fd("Invalid integer for time to eat", 2), 1);
	if (!(ft_atoll(av[4]) < INT_MAX && ft_atoll(av[4]) > -1))
		return (ft_putendl_fd("Invalid integer for time to sleep", 2), 1);
	if (av[5])
	{
		if (!(ft_atoll(av[5]) < INT_MAX && ft_atoll(av[5]) > 0))
			return (ft_putendl_fd("Invalid integer for meal goal", 2), 1);
	}
	return (0);
}

int	init_philo(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->number_of_philosophers);
	if (!table->philos)
		return (1);
	i = 0;
	while (i < table->number_of_philosophers)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = table->start_time;
		table->philos[i].table = table;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1)
			% table->number_of_philosophers];
		i++;
	}
	return (0);
}

int	init_table_n_philo(char **av, t_table *table)
{
	int	i;

	table->number_of_philosophers = ft_atoll(av[1]);
	table->time_to_die = ft_atoll(av[2]);
	table->time_to_eat = ft_atoll(av[3]);
	table->time_to_sleep = ft_atoll(av[4]);
	if (av[5])
		table->meal_goal = ft_atoll(av[5]);
	else
		table->meal_goal = -1;
	table->dead_flag = 0;
	pthread_mutex_init(&table->print_lock, NULL);
	pthread_mutex_init(&table->dead_lock, NULL);
	pthread_mutex_init(&table->meal_lock, NULL);
	table->forks = malloc(sizeof(pthread_mutex_t)
			* table->number_of_philosophers);
	if (!table->forks)
		return (1);
	i = -1;
	while (++i < table->number_of_philosophers)
		pthread_mutex_init(&table->forks[i], NULL);
	if (init_philo(table))
		return (1);
	return (0);
}

int	parse(char **av, t_table *table)
{
	if (table_error(av) || init_table_n_philo(av, table))
		return (1);
	return (0);
}
