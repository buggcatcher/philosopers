/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:19:13 by mailinci          #+#    #+#             */
/*   Updated: 2024/11/30 17:32:52 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


const char *set_color(const char *event)
{
    const char *color = RESET;

    if (ft_strcmp(event, "is thinking") == 0)
        color = BLUE;
    else if (ft_strcmp(event, "is eating") == 0)
        color = GREEN;
    else if (ft_strcmp(event, "is sleeping") == 0)
        color = YELLOW;
    else if (ft_strcmp(event, "is dead") == 0)
        color = RED;
    else if (ft_strcmp(event, "is full") == 0)
        color = CYAN;
	else if (ft_strcmp(event, "picked up left fork") == 0 || \
	ft_strcmp(event, "picked up right fork") == 0)
        color = MAGENTA;  

    return color;
}


void pretty_output(int time, int max_width, int philosopher_id, const char *event)
{
    int num_digits;
    int temp;
    int num_dots;
    int i;

    const char *color = set_color(event);
    if (time == 0)
	{
        printf("%s......0      id:%d      %s\n" RESET, color, philosopher_id, event);
        return;
    }
    num_digits = 0;
    temp = time;
    while (temp > 0)
	{
        temp /= 10;
        num_digits++;
    }
    num_dots = max_width - num_digits;
    i = -1;
    while (++i < num_dots)
        printf(".");

    printf("%s%d     id:%d    \t%s\n" RESET, color, time, philosopher_id, event);
}


void print_status(t_philo *philo, const char *status)
{
    int time;
    int max_width;

	time = get_time() - philo->table->start_time;
	max_width = 7;
    pthread_mutex_lock(&philo->table->supervisor.lock_print);
    pretty_output(time, max_width, philo->id, status);
    pthread_mutex_unlock(&philo->table->supervisor.lock_print);
}

void eat(t_philo *philo)
{
    print_status(philo, "is eating");
    philo->last_meal_time = get_time();
    usleep(philo->table->args.time_to_eat * 1000);
    philo->number_of_meals++;
    if (philo->table->args.number_of_times_each_philosopher_must_eat != -1 &&
        philo->number_of_meals >= philo->table->args.number_of_times_each_philosopher_must_eat)
    {
        philo->full_stomach = true;
    }
}

void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    while (!philo->table->end_time)
    {
        print_status(philo, "is thinking");
        pthread_mutex_lock(&philo->left_fork->fork);
        print_status(philo, "picked up left fork");
        pthread_mutex_lock(&philo->right_fork->fork);
        print_status(philo, "picked up right fork");
        eat(philo);
        pthread_mutex_unlock(&philo->left_fork->fork);
        pthread_mutex_unlock(&philo->right_fork->fork);
        print_status(philo, "is sleeping");
        usleep(philo->table->args.time_to_sleep * 1000);
    }
    return NULL;
}
