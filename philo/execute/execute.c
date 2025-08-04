#include "../inc/philo.h"

void take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");

		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		if (philo->table->dead_flag == 0)
		{
			pthread_mutex_lock(philo->right_fork);
			print_status(philo, "has taken a fork");

			pthread_mutex_lock(philo->left_fork);
			print_status(philo, "has taken a fork");
		}
	}
}

void eat(t_philo *philo)
{
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->meal_lock);
	usleep(philo->table->time_to_eat * 1000);
}

void drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void sleep_philo(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
}

void *life_cycle(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	
	if (philo->table->number_of_philosophers == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		usleep(philo->table->time_to_die * 1000);
		pthread_mutex_unlock(philo->left_fork);
		print_status(philo, "died");
		return (NULL);
	}
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

int	execute(t_table *table)
{
    int		i;
    int		finished;
    long	time;
    long	last_meal;

    table->start_time = get_time();
    pthread_mutex_lock(&table->meal_lock);
    i = 0;
    while (i < table->number_of_philosophers)
    {
        table->philos[i].last_meal = table->start_time;
        i++;
    }
    pthread_mutex_unlock(&table->meal_lock);

    i = 0;
    while (i < table->number_of_philosophers)
    {
        pthread_create(&table->philos[i].thread, NULL, life_cycle, &table->philos[i]);
        i++;
    }
    usleep(100);

    while (!get_dead_flag(table))
    {
        i = 0;
        finished = 0;
        while (i < table->number_of_philosophers)
        {
            pthread_mutex_lock(&table->meal_lock);
            last_meal = table->philos[i].last_meal;
            time = get_time();
            if (time - last_meal > table->time_to_die)
            {
                print_status(&table->philos[i], "died");
                set_dead(table);
                pthread_mutex_unlock(&table->meal_lock);
                break;
            }
            if (table->meal_goal > 0 && table->philos[i].meals_eaten >= table->meal_goal)
                finished++;
            pthread_mutex_unlock(&table->meal_lock);
            i++;
        }
        if (table->meal_goal > 0 && finished == table->number_of_philosophers)
        {
            set_dead(table);
            break;
        }
        usleep(1000);
    }
    i = 0;
    while (i < table->number_of_philosophers)
    {
        pthread_join(table->philos[i].thread, NULL);
        i++;
    }
    return (0);
}
