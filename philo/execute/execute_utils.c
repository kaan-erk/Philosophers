/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:24:37 by ktoraman          #+#    #+#             */
/*   Updated: 2025/08/04 20:25:54 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	is_dead(t_table *table)
{
	int	flag;

	pthread_mutex_lock(&table->dead_lock);
	flag = table->dead_flag;
	pthread_mutex_unlock(&table->dead_lock);
	return (flag);
}

void	set_dead(t_table *table)
{
	pthread_mutex_lock(&table->dead_lock);
	table->dead_flag = 1;
	pthread_mutex_unlock(&table->dead_lock);
}

int	get_dead_flag(t_table *table)
{
	int	flag;

	pthread_mutex_lock(&table->dead_lock);
	flag = table->dead_flag;
	pthread_mutex_unlock(&table->dead_lock);
	return (flag);
}

void	eat(t_philo *philo)
{
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->meal_lock);
	usleep(philo->table->time_to_eat * 1000);
}

void	sleep_philo(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
}
