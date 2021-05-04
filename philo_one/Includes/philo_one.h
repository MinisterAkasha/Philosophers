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

/*
** free
*/

void free_forks(pthread_mutex_t *forks, int forks_num);
void free_everything(t_state *state);

/*
** free
*/
int create_threads(t_state *state);

#endif