#include "philo_one.h"

void	*philo_life_cycle(void *args)
{
	t_state	*state;
	int		pos;
	int		forks[2];

	state = (t_state *) args;
	pos = get_philo_pos(state);
	get_forks_index(pos, state->philo_options.p_num, &forks);
	while (TRUE)
	{
		if (state->philo[pos].eat_times == state->philo_options.times_need_eat)
			return (NULL);
		philo_take_forks(&state->forks[forks[0]], \
			&state->forks[forks[1]], pos, state);
		philo_eating(state, pos, forks);
		philo_sleeping(state, pos);
		philo_thinking(state, pos);
	}
	return (NULL);
}
