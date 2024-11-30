/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:30:40 by mailinci          #+#    #+#             */
/*   Updated: 2024/11/30 17:34:12 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// crea i thread dei filosofi e li associa alla loro routine
int start_philosophers(t_table *table)
{
    int i;

    table->start_time = get_time();
    i = 0;
    while (i < table->args.philo_nbr)
    {
        table->philos[i].last_meal_time = table->start_time;
        if (pthread_create(&table->philos[i].thread, NULL, philo_routine, &table->philos[i]) != 0)
        {
            printf("Error: Could not create thread for philosopher %d\n", i);
            return (1);
        }
        i++;
    }
    return (0);
}

int start_dinner(t_table *table)
{
    if (start_philosophers(table) != 0)
    {
        printf("Error: Simulation failed to start\n");
        free_table(table);
        return 1;
    }
    while (!table->end_time)
    {
        usleep(1000);
    }
    return 0;
}

void free_table(t_table *table)
{
    int i;

    i = -1;
    while (++i < table->args.philo_nbr)
        pthread_join(table->philos[i].thread, NULL);
    i = -1;
    free(table->philos);
    i = -1;
    while (++i < table->args.philo_nbr)
        pthread_mutex_destroy(&table->fork[i].fork);
    free(table->fork);
    pthread_mutex_destroy(&table->supervisor.lock_print);
    pthread_mutex_destroy(&table->supervisor.lock_check);
    pthread_mutex_destroy(&table->supervisor.lock_end);
}


