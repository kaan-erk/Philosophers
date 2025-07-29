#include "../inc/philo.h"

void *thread_test(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    printf("Philo id: %d: %s\n", philo->id, "Hello");
    return (NULL);
}

int execute(t_table *table)
{
    int i;

    i = 0;
    while (i < table->number_of_philosophers)
    {
        pthread_create(&table->philos[i].thread, NULL, thread_test, (void *)&table->philos[i]);
        pthread_join(table->philos[i].thread, NULL);
        i++;
    }
    return (0);
}