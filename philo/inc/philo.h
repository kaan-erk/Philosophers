/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:33:08 by ktoraman          #+#    #+#             */
/*   Updated: 2025/07/23 15:45:20 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct	s_table
{
	int	nuber_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}				t_table;

//utils utils.c
void			ft_putendl_fd(char *s, int fd);
long long		ft_atoll(const char *str);

#endif