#include "philo_two.h"

void	philo_put_forks(int pos, t_state *state)
{
	sem_post(state->forks_sem);
	sem_post(state->forks_sem);
}

void	philo_take_forks(int pos, t_state *state)
{
	state->philo[pos].state = IS_TAKE_FORK;
	sem_wait(state->take_forks_sem);
	sem_wait(state->forks_sem);
	write_message(state, pos);
	sem_wait(state->forks_sem);
	write_message(state, pos);
	sem_post(state->take_forks_sem);
}

void	philo_eating(t_state *state, int pos)
{
	state->philo[pos].state = IS_EATING;
	write_message(state, pos);
	state->philo[pos].last_eat = get_current_time(state);
	state->philo[pos].eat_times++;
	my_usleep(state->philo_options.time_to_eat * 1000);
	philo_put_forks(pos, state);
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
