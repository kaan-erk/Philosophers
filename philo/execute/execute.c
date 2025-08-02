#include "../inc/philo.h"

void *life_cycle(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    
    while (is_dead(philo->table))
    {
        
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