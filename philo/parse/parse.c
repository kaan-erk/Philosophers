/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:56:07 by ktoraman          #+#    #+#             */
/*   Updated: 2025/07/23 17:14:15 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	alpha_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isalpha(av[i][j])) 
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int parse_table_error(char **av)
{
	if (alpha_check(av))
		return(ft_putendl_fd("Alphabetical Character in args", 2) ,1);
	if (!(ft_atoll(av[1]) < INT_MAX && ft_atoll(av[1]) > 0))
			return (ft_putendl_fd("Invalid integer for number of philosophers", 2), 1);
	if (!(ft_atoll(av[2]) < INT_MAX && ft_atoll(av[2]) > -1))
			return (ft_putendl_fd("Invalid integer for time to die", 2), 1);
	if (!(ft_atoll(av[3]) < INT_MAX && ft_atoll(av[3]) > -1))
			return (ft_putendl_fd("Invalid integer for time to eat", 2), 1);
	if (!(ft_atoll(av[4]) < INT_MAX && ft_atoll(av[4]) > -1))
		return (ft_putendl_fd("Invalid integer for time to sleep", 2), 1);
	if (av[5])
	{
		if (!(ft_atoll(av[5]) < INT_MAX && ft_atoll(av[5]) > -1))	
			return (ft_putendl_fd("Invalid integer for meal goal", 2), 1);
	}
	return (0);
}

int	parse(char **av)
{
	if (parse_table_error(av))
		return (1);
	//parse table
	return (0);
}