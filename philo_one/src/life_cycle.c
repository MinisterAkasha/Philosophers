#include "philo_one.h"

int	get_philo_pos(t_state *state)
{
	int pos;
	pthread_mutex_lock(&state->philo_pos_mutex);
	pos = state->philo_pos;
	pthread_mutex_unlock(&state->philo_pos_mutex);
	return (pos);
}

void* philo_life_cycle(void *args)
{
	t_state *state;
	int		pos;

	state = (t_state*) args;
	pos = get_philo_pos(state);
	// pthread_mutex_lock(&state->forks[0]);

	// printf("1 :>> %d\n", 1);
	// pthread_mutex_unlock(&state->forks[0]);
	return (NULL);
}