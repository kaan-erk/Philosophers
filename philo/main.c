/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:20:26 by ktoraman          #+#    #+#             */
/*   Updated: 2025/07/23 15:51:47 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

int parse_table(char **av)
{
	if (!(ft_atoll(av[1]) < INT_MAX && ft_atoll(av[1]) > INT_MIN))
	{
		ft_putendl_fd("Invalid integer for Number of philosophers", 2);
		return (-1);
	}
	if (!(ft_atoll(av[2]) < INT_MAX && ft_atoll(av[2]) > INT_MIN))
	{
		ft_putendl_fd("Invalid integer for time to die", 2);
		return (-1);
	}
	if (!(ft_atoll(av[3]) < INT_MAX && ft_atoll(av[3]) > INT_MIN))
	{
		ft_putendl_fd("Invalid integer for time to eat", 2);
		return (-1);
	}
	if (!(ft_atoll(av[1]) < INT_MAX && ft_atoll(av[1]) > INT_MIN))
	{
		ft_putendl_fd("Invalid integer for time to sleep", 2);
		return (-1);
	}
	return (0);
}

int	parse(char **av)
{
	parse_table(av);
	return (0);
}

int main(int ac, char **av)
{
	(void)av;
	if (ac == 5)
		parse(av);
	else
		write(2, "Invalid number of args\n", 24);
}