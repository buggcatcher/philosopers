#ifndef PHILO_H
# define PHILO_H

#include <fcntl.h>
#include <limits.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define BLACK   "\033[1;30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define RESET 	"\033[0m"

typedef struct s_argouments
{
	int	philo_nbr;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_argouments;

typedef struct s_fork			// every fork is a mutex maybe i can use assigned the position 
{					  			// of the fork in its array 
	pthread_mutex_t	fork;
	int				fork_id; 		//UNUSED!
}	t_fork;

typedef struct s_table t_table; // stfu dont yell at me

typedef struct s_philo 			// every philo is a thread
{
	int			id;
	int			number_of_meals;  	//UNUSED! (INFATTI LA SIMULAZIONE NON FINISCE MAI)
	long		last_meal_time;   	//UNUSED! (QUANTO TEMPO E' PASSATO DALL'ULTIMO PASTO)
	bool		full_stomach; 	  	//UNUSED!
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_table		*table;
	pthread_t	thread; 		// feed into pthread_create
}	t_philo;

typedef struct s_supervisor
{
	pthread_mutex_t	lock_print; // stampa
	pthread_mutex_t	lock_check; // controllo stato
	pthread_mutex_t	lock_end;	// fine simulazione
}	t_supervisor;

typedef struct s_table
{
	t_argouments	args;
	t_fork			*fork;		// array of forks
	t_philo			*philos;
	t_supervisor	supervisor;          
	long			start_time; // simulation start
	bool			end_time; 	// one dies or all have full_stomach

}	t_table;


t_argouments	parse_argouments(int argc, char **argv);
void			init_table(t_table *table);
void			free_table(t_table *table);
void			*safe_alloc(size_t n_elem, size_t bytes, const char *description);
int				start_dinner(t_table *table);
void			*philo_routine(void *arg);
unsigned long	get_time(void);
int				ft_strcmp(const char *s1, const char *s2);


// debug functions
void print_argouments(t_argouments args);
void print_table(t_table *table);

#endif
