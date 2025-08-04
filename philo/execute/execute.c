/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:25:30 by ktoraman          #+#    #+#             */
/*   Updated: 2025/08/04 20:34:06 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	init_philosophers(t_table *table)
{
	int	i;

	table->start_time = get_time();
	pthread_mutex_lock(&table->meal_lock);
	i = 0;
	while (i < table->number_of_philosophers)
	{
		table->philos[i].last_meal = table->start_time;
		i++;
	}
	pthread_mutex_unlock(&table->meal_lock);
}

static int	check_philosopher_status(t_table *table, int i, int *finished)
{
	long	time;
	long	last_meal;

	pthread_mutex_lock(&table->meal_lock);
	last_meal = table->philos[i].last_meal;
	time = get_time();
	if (time - last_meal >= table->time_to_die)
	{
		print_status(&table->philos[i], "died");
		set_dead(table);
		pthread_mutex_unlock(&table->meal_lock);
		return (1);
	}
	if (table->meal_goal > 0
		&& table->philos[i].meals_eaten >= table->meal_goal)
		(*finished)++;
	pthread_mutex_unlock(&table->meal_lock);
	return (0);
}

static void	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}

static int	monitor_philosophers(t_table *table)
{
	int	i;
	int	finished;

	while (!get_dead_flag(table))
	{
		i = 0;
		finished = 0;
		while (i < table->number_of_philosophers)
		{
			if (check_philosopher_status(table, i, &finished))
				return (1);
			i++;
		}
		if (table->meal_goal > 0 && finished == table->number_of_philosophers)
		{
			set_dead(table);
			break ;
		}
		usleep(1000);
	}
	return (0);
}

int	execute(t_table *table)
{
	int	i;

	i = 0;
	init_philosophers(table);
	while (i < table->number_of_philosophers)
	{
		pthread_create(&table->philos[i].thread, NULL, life_cycle,
			&table->philos[i]);
		i++;
	}
	usleep(100);
	monitor_philosophers(table);
	join_threads(table);
	return (0);
}
