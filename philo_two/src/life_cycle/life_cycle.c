#include "philo_two.h"

void	*philo_life_cycle(void *args)
{
	t_state	*state;
	int		pos;

	state = (t_state *) args;
	pos = get_philo_pos(state);
	while (TRUE)
	{
		if (state->philo[pos].eat_times == state->philo_options.times_need_eat)
		{
			state->eaten_philos[pos] = TRUE;
			return (NULL);
		}
		philo_take_forks(pos, state);
		philo_eating(state, pos);
		philo_sleeping(state, pos);
		philo_thinking(state, pos);
	}
	return (NULL);
}
