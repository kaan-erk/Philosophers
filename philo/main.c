/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:20:26 by ktoraman          #+#    #+#             */
/*   Updated: 2025/08/04 20:33:09 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

void	free_table(t_table *table)
{
	int	i;

	if (table->forks)
	{
		i = 0;
		while (i < table->number_of_philosophers)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
	}
	if (table->philos)
		free(table->philos);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->meal_lock);
	pthread_mutex_destroy(&table->dead_lock);
}

int	main(int ac, char **av)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	table.start_time = get_time();
	if (ac == 5 || ac == 6)
	{
		if (parse(av, &table))
		{
			free_table(&table);
			return (1);
		}
		execute(&table);
	}
	else
		write(2, "Invalid number of args\n", 24);
	free_table(&table);
	return (0);
}
