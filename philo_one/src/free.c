#include "philo_one.h"

void free_forks(pthread_mutex_t *forks, int forks_num)
{
	int i;

	i = 0;
	while (i < forks_num)
		pthread_mutex_destroy(&forks[i++]);
	free(forks);
}

void free_everything(t_state *state)
{
	free_forks(state->forks, state->philo_options.p_num);
	free(state->philo);
	pthread_mutex_destroy(&state->message_mutex);
	pthread_mutex_destroy(&state->philo_pos_mutex);
	free(state);
}
