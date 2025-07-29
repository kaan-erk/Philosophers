/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman < ktoraman@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:33:08 by ktoraman          #+#    #+#             */
/*   Updated: 2025/07/23 18:24:02 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct	s_table
{
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				dead_flag;
	int				meal_goal;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*forks;
	struct s_philo	*philos;
}				t_table;

typedef struct	s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
}				t_philo;

//utils utils.c
void		ft_putendl_fd(char *s, int fd);
int			ft_isalpha(int a);
long long	ft_atoll(const char *str);
//parse parse.c
int				parse(char **av, t_table *table);
//execute execute.c
int			execute(t_table *table);

#endif