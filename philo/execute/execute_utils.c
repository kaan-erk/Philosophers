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
