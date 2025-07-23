/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:20:26 by ktoraman          #+#    #+#             */
/*   Updated: 2025/07/23 17:08:49 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

int main(int ac, char **av)
{
	(void)av;
	if (ac == 5 || ac == 6)
	{
		if (parse(av))
			return (1);
	}
	else
		write(2, "Invalid number of args\n", 24);
	return (0);
}