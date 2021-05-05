#include "philo_one.h"

void	philo_put_forks(pthread_mutex_t *left_fork, \
	pthread_mutex_t *right_fork, int pos)
{
	if ((pos & 1) == TRUE)
	{
		pthread_mutex_unlock(right_fork);
		pthread_mutex_unlock(left_fork);
	}
	else if ((pos & 1) == FALSE)
	{
		pthread_mutex_unlock(left_fork);
		pthread_mutex_unlock(right_fork);
	}
}

void	philo_take_forks(pthread_mutex_t *left_fork, \
	pthread_mutex_t *right_fork, int pos, t_state *state)
{
	state->philo[pos].state = IS_TAKE_FORK;
	if ((pos & 1) == TRUE)
	{
		pthread_mutex_lock(left_fork);
		write_message(state, pos);
		pthread_mutex_lock(right_fork);
		write_message(state, pos);
	}
	else if ((pos & 1) == FALSE)
	{
		pthread_mutex_lock(right_fork);
		write_message(state, pos);
		pthread_mutex_lock(left_fork);
		write_message(state, pos);
	}
}

void	philo_eating(t_state *state, int pos, int forks[2])
{
	state->philo[pos].state = IS_EATING;
	write_message(state, pos);
	state->philo[pos].last_eat = get_current_time(state);
	state->philo[pos].eat_times++;
	my_usleep(state->philo_options.time_to_eat * 1000);
	philo_put_forks(&state->forks[forks[0]], &state->forks[forks[1]], pos);
}

void	philo_sleeping(t_state *state, int pos)
{
	state->philo[pos].state = IS_SLEEPING;
	write_message(state, pos);
	my_usleep(state->philo_options.time_to_sleep * 1000);
}

void	philo_thinking(t_state *state, int pos)
{
	state->philo[pos].state = IS_THINKING;
	write_message(state, pos);
}
