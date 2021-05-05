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


int init(t_state *state, char **argv);
void update_current_time(t_state **state);

/*
** free
*/

void free_forks(pthread_mutex_t *forks, int forks_num);
void free_everything(t_state *state);

/*
** free
*/
int create_threads(t_state *state);

/*
** life_cycle
*/

void* philo_life_cycle(void *args);

/*
** observer
*/

void update_current_time(t_state **state);
int	get_dead_philo_index(t_state *state);
int check_has_every_philo_eaten(t_state *state);
void* observer(void *args);

#endif