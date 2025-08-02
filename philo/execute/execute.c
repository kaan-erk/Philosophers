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
        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "has taken a fork");

        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork");
    }
}

void eat(t_philo *philo)
{
    print_status(philo, "is eating");
    philo->last_meal = get_time();
    philo->meals_eaten++;
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
    long    time;
    
    while (!is_dead(philo->table))
    {
        time = get_time();
        if (time - philo->last_meal >= philo->table->time_to_die)
        {
            print_status(philo, "died");
            set_dead(philo->table);
            break ;
        }
        take_forks(philo);
        eat(philo);
        drop_forks(philo);
        sleep_philo(philo);
        print_status(philo, "is thinking");
    }
    return (NULL);
}

int execute(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_of_philosophers)
    {
        pthread_create(&table->philos[i].thread, NULL, life_cycle, (void *)&table->philos[i]);
        i++;
    }
    i = 0;
    while (i < table->number_of_philosophers)
    {
        pthread_join(table->philos[i].thread, NULL);
        i++;
    }
    return (0);
}
