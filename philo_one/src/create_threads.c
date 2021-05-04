#include "philo_one.h"

void* observer(void *args)
{
	t_state *state;
	int		i;

	state = (t_state*) args;
	while (1)
	{
		i = 0;
		while (i < state->philo_options.p_num)
		{
			if (state->philo[i].state == IS_DEAD)
			{
				write_message(state->message_mutex, i, IS_DEAD);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

int create_threads(t_state *state)
{
	int i;

	i = 0;
	while (i < state->philo_options.p_num)
	{
		state->philo_pos = i;
		if (pthread_create(&state->philo[i].philo_thread, NULL, philo_life_cycle, state) != 0)
			return (1);
		pthread_join(state->philo[i].philo_thread, NULL);
		i++;
	}
	if (pthread_create(&state->observer_pt, NULL, observer, state) != 0)
		return (1);
	pthread_join(state->observer_pt, NULL);
	return (0);
}