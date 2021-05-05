#include "philo_one.h"

int	get_philo_pos(t_state *state)
{
	int pos;

	pthread_mutex_lock(&state->philo_pos_mutex);
	pos = state->philo_pos++;
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

void philo_eating(t_state *state, int pos, int forks[2])
{
	pthread_mutex_lock(&state->forks[forks[0]]);
	pthread_mutex_lock(&state->forks[forks[1]]);
	state->philo[pos].state = IS_TAKE_FORK;
	write_message(state, pos);
	write_message(state, pos);
	state->philo[pos].state = IS_EATING;
	state->philo[pos].last_eat = state->current_time;
	write_message(state, pos);
	state->philo[pos].eat_times++;
	usleep(state->philo_options.time_to_eat * 1000);
	pthread_mutex_unlock(&state->forks[forks[0]]);
	pthread_mutex_unlock(&state->forks[forks[1]]);
}

void philo_sleeping(t_state *state, int pos)
{
	state->philo[pos].state = IS_SLEEPING;
	write_message(state, pos);
	usleep(state->philo_options.time_to_sleep * 1000);
}

void philo_thinking(t_state *state, int pos)
{
	state->philo[pos].state = IS_THINKING;
	write_message(state, pos);
}

void* philo_life_cycle(void *args)
{
	t_state *state;
	int		pos;
	int		forks[2];

	state = (t_state*) args;
	pos = get_philo_pos(state);
	get_forks_index(pos, state->philo_options.p_num, &forks);
	while (TRUE)
	{
		if (state->philo[pos].eat_times == state->philo_options.times_need_to_eat)
			return (NULL);
		philo_eating(state, pos, forks);
		philo_sleeping(state, pos);
		philo_thinking(state, pos);
	}
	return (NULL);
}