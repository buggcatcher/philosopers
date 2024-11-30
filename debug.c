#include "philo.h"

void print_argouments(t_argouments args)
{
    //printf(BLACK "BLACK" RESET);
    printf(RED "RED " RESET);
    printf(YELLOW "YELLOW " RESET);
    printf(GREEN "GREEN " RESET);
    printf(BLUE "BLUE " RESET);
    printf(MAGENTA "MAGENTA " RESET);
    printf(CYAN "SAYAN " RESET);
    //printf(WHITE "WHITE" RESET);
    puts("");

    printf("Number of philosophers: %d\n", args.philo_nbr);
    printf("Time to die: %d ms\n", args.time_to_die);
    printf("Time to eat: %d ms\n", args.time_to_eat);
    printf("Time to sleep: %d ms\n", args.time_to_sleep);

    if (args.number_of_times_each_philosopher_must_eat == -1)
        printf("Number of times each philosopher must eat: Not specified\n");
    else
        printf("Number of times each philosopher must eat: %d\n", args.number_of_times_each_philosopher_must_eat);
}

void print_table(t_table *table)
{
    int i = 0;
    while (i < table->args.philo_nbr)
    {
        printf("Filosofo %d ha la forchetta %d (sx) e la forchetta %d (dx)\n",
               table->philos[i].id,
               table->philos[i].left_fork->fork_id,
               table->philos[i].right_fork->fork_id);
        i++;
    }
}