#include "philo_one.h"

int	get_philo_pos(t_state *state)
{
	int pos;
	pthread_mutex_lock(&state->philo_pos_mutex);
	pos = state->philo_pos;
	pthread_mutex_unlock(&state->philo_pos_mutex);
	return (pos);
}

void get_forks_index(int pos, int philo_num, int (*forks)[2])
{
	(*forks)[0] = pos;
	if (pos == philo_num - 1)
		(*forks)[1] = 0;
	else
		(*forks)[1] = pos + 1;
}

void* philo_life_cycle(void *args)
{
	t_state *state;
	int		pos;
	int		forks[2];

	state = (t_state*) args;
	pos = get_philo_pos(state);
	get_forks_index(pos, state->philo_options.p_num, &forks);

	pthread_mutex_lock(&state->forks[forks[0]]);
	pthread_mutex_lock(&state->forks[forks[1]]);

	// printf("1 :>> %d\n", 1);
	pthread_mutex_unlock(&state->forks[forks[0]]);
	pthread_mutex_unlock(&state->forks[forks[1]]);
	return (NULL);
}