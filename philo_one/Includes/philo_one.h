#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/time.h>

# include "utils.h"
# include "validate.h"

typedef enum e_Bool {
	FALSE,
	TRUE
}	t_Bool;

typedef enum e_state_type {
	EATING,
	THINKING,
	SLEEPING,
	DEAD
}	t_state_type;

typedef struct s_philos_options {
	int	p_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_need_to_eat;
}								t_philos_options;

typedef struct s_philo_state {
	int	state;
}								t_philo_state;

typedef struct s_state {
	int					start_time;
	t_philo_state		*philo;
	pthread_mutex_t		*forks;

	int					error;
	t_philos_options	philo_options;
}				t_state;

void init(t_state *state, char **argv);

/*
** free
*/

void free_forks(pthread_mutex_t *forks, int forks_num);
void free_everything(t_state *state);

#endif