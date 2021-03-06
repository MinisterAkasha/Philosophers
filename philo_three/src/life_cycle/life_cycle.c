#include "philo_three.h"

int	philo_life_cycle(t_state *state)
{
	int			pos;
	pthread_t	philo_thread;

	pos = state->philo_pos;
	state->philo[pos].last_eat = get_current_time(state);
	if (pthread_create(&philo_thread, NULL, observer, state) != 0)
		return (2);
	pthread_detach(philo_thread);
	while (TRUE)
	{
		if (state->philo[pos].eat_times == state->philo_options.times_need_eat)
			exit(0);
		philo_take_forks(pos, state);
		philo_eating(state, pos);
		philo_sleeping(state, pos);
		philo_thinking(state, pos);
	}
	return (0);
}
