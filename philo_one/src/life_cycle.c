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

void philo_put_forks(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork, int pos)
{
	if ((pos & 1) == TRUE)//1-3-5...
	{
		pthread_mutex_unlock(right_fork);
		pthread_mutex_unlock(left_fork);
	}
	else if ((pos & 1) == FALSE)//0-2-4...
	{
		pthread_mutex_unlock(left_fork);
		pthread_mutex_unlock(right_fork);
	}
}

void philo_take_forks(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork, int pos, t_state *state)
{
	state->philo[pos].state = IS_TAKE_FORK;
	if ((pos & 1) == TRUE)//1-3-5...
	{
		pthread_mutex_lock(left_fork);
		write_message(state, pos);
		pthread_mutex_lock(right_fork);
		write_message(state, pos);
	}
	else if ((pos & 1) == FALSE)//0-2-4...
	{
		pthread_mutex_lock(right_fork);
		write_message(state, pos);
		pthread_mutex_lock(left_fork);
		write_message(state, pos);
	}
}

void philo_eating(t_state *state, int pos, int forks[2])
{
	state->philo[pos].state = IS_EATING;
	write_message(state, pos);
	state->philo[pos].last_eat = get_current_time(state);
	state->philo[pos].eat_times++;
	usleep(state->philo_options.time_to_eat * 1000);
	philo_put_forks(&state->forks[forks[0]], &state->forks[forks[1]], pos);
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
	// printf("POS: %d, FORKS: %d --- %d\n", pos, forks[0], forks[1]);
	while (TRUE)
	{
		if (state->philo[pos].eat_times == state->philo_options.times_need_to_eat)
			return (NULL);
		philo_take_forks(&state->forks[forks[0]], &state->forks[forks[1]], pos, state);
		philo_eating(state, pos, forks);
		philo_sleeping(state, pos);
		philo_thinking(state, pos);
	}
	return (NULL);
}