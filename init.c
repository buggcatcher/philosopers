/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:03:41 by mailinci          #+#    #+#             */
/*   Updated: 2024/11/30 15:05:40 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_supervisor(t_table *table)
{
    pthread_mutex_init(&table->supervisor.lock_print, NULL);
    pthread_mutex_init(&table->supervisor.lock_check, NULL);
    pthread_mutex_init(&table->supervisor.lock_end, NULL);

}

void init_table(t_table *table)
{
	int i;
    table->start_time = time(NULL);
    table->end_time = false;

	table->fork = safe_alloc(table->args.philo_nbr, sizeof(t_fork), "forks");
    table->philos = safe_alloc(table->args.philo_nbr, sizeof(t_philo), "philos");
	i = -1;
    while (++i < table->args.philo_nbr)
    {
        pthread_mutex_init(&table->fork[i].fork, NULL);
        table->fork[i].fork_id = i;
    }
    i = -1;
    while (++i < table->args.philo_nbr)
    {
        table->philos[i].id = i;
        table->philos[i].number_of_meals = 0;
        table->philos[i].last_meal_time = 0;
        table->philos[i].full_stomach = false;
        table->philos[i].left_fork = &table->fork[i];
        table->philos[i].right_fork = &table->fork[(i + 1) % table->args.philo_nbr];
        table->philos[i].table = table;
    }
    init_supervisor(table);
}

