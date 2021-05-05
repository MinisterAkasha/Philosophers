#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/time.h>

# include "structures.h"
# include "utils.h"
# include "validate.h"
# include "write_message.h"

/*
** free
*/

int		init(t_state *state, char **argv);
void	init_philos_options(t_philos_options *philo_options, char **argv);
void	init_start_time(long *start_time);
void	init_mutex(t_state *state, int forks_num, int *error);
void	init_philosophers(t_philo_state **philo, int philo_num, \
	int start_time);
void	init_str_message(char *str_message[5]);

/*
** free
*/

void free_forks(pthread_mutex_t *forks, int forks_num);
void free_everything(t_state *state);

/*
** create_threads
*/
int create_threads(t_state *state);

/*
** life_cycle
*/

void* philo_life_cycle(void *args);

/*
** observer
*/

int	get_dead_philo_index(t_state *state);
int check_has_every_philo_eaten(t_state *state);
void* observer(void *args);

/*
** exit_erorr
*/

int	exit_error(char *error, t_state *state);

#endif