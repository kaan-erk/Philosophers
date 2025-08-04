/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:27:35 by ktoraman          #+#    #+#             */
/*   Updated: 2025/08/04 23:14:22 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	drop_forks(t_philo *philo)
{
	if (philo->has_left_fork)
	{
		pthread_mutex_unlock(philo->left_fork);
		philo->has_left_fork = 0;
	}
	if (philo->has_right_fork)
	{
		pthread_mutex_unlock(philo->right_fork);
		philo->has_right_fork = 0;
	}
}

void	take_forks_else(t_philo *philo)
{
	if (!is_dead(philo->table))
	{
		pthread_mutex_lock(philo->right_fork);
		philo->has_right_fork = 1;
		print_status(philo, "has taken a fork");
		if (is_dead(philo->table))
		{
			drop_forks(philo);
			return ;
		}
		pthread_mutex_lock(philo->left_fork);
		philo->has_left_fork = 1;
		print_status(philo, "has taken a fork");
	}
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		philo->has_left_fork = 1;
		print_status(philo, "has taken a fork");
		if (is_dead(philo->table))
		{
			drop_forks(philo);
			return ;
		}
		pthread_mutex_lock(philo->right_fork);
		philo->has_right_fork = 1;
		print_status(philo, "has taken a fork");
	}
	else
	{
		usleep(1000);
		take_forks_else(philo);
	}
}

void	*life_cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->has_left_fork = 0;
	philo->has_right_fork = 0;
	if (philo->id % 2 == 0)
		usleep(200);
	// if (philo->table->number_of_philosophers == 1)
	// {
	// 	pthread_mutex_lock(philo->left_fork);
	// 	print_status(philo, "has taken a fork");
	// 	usleep(philo->table->time_to_die * 1000);
	// 	pthread_mutex_unlock(philo->left_fork);
	// 	return (print_status(philo, "died"), NULL);
	// }
	while (!is_dead(philo->table))
	{
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		sleep_philo(philo);
		print_status(philo, "is thinking");
	}
	return (NULL);
}
