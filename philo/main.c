/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:20:26 by ktoraman          #+#    #+#             */
/*   Updated: 2025/07/23 18:38:29 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

int main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		if (parse(av, &table))
		{
			//free
			return (1);
		}
		execute(&table);
	}
	else
		write(2, "Invalid number of args\n", 24);
	//free
	return (0);
}