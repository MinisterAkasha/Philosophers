#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>

# include "structures.h"
# include "utils.h"
# include "validate.h"
# include "write_message.h"

# define SEM_FORKS "SEM_FORKS"
# define SEM_MESSAGE "SEM_MESSAGE"
# define SEM_PHILO_TAKE_FORKS "SEM_PHILO_TAKE_FORKS"
# define SEM_PHILO_POS "SEM_PHILO_POS"
# define SEM_DEAD_PHILO "SEM_DEAD_PHILO"

/*
** free
*/

int		init(t_state *state, char **argv);
void	init_philos_options(t_philos_options *philo_options, char **argv);
void	init_semaphores(t_state *state, int *error);
void	init_start_time(long *start_time);
void	init_philosophers(t_philo_state **philo, int philo_num, \
	int start_time, int *error);
void	init_str_message(char *str_message[5]);

/*
** free
*/

void	free_everything(t_state *state);

/*
** create_threads
*/

int		create_processes(t_state *state);

/*
** life_cycle
*/

int		philo_life_cycle(t_state *state);
int		get_philo_pos(t_state *state);
void	get_forks_index(int pos, int philo_num, int (*forks)[2]);
void	philo_put_forks(int pos, t_state *state);
void	philo_take_forks(int pos, t_state *state);
void	philo_eating(t_state *state, int pos);
void	philo_sleeping(t_state *state, int pos);
void	philo_thinking(t_state *state, int pos);

/*
** observer
*/

int		get_dead_philo_index(t_state *state);
// int		check_has_every_philo_eaten(t_state *state);
void	*observer(void *args);

/*
** exit_erorr
*/

void	exit_error(int error_code, t_state *state);

#endif