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
				//TODO write_mesasge();
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

void* philo_life_cycle(void *args)
{
	t_state *state;

	state = (t_state*) args;
	pthread_mutex_lock(&state->forks[0]);
	printf("1 :>> %d\n", 1);
	pthread_mutex_unlock(&state->forks[0]);
	return (NULL);
}

int create_threads(t_state *state)
{
	int i;

	i = 0;
	while (i < state->philo_options.p_num)
	{
		if (pthread_create(&state->philo[i].philo_thread, NULL, philo_life_cycle, state) != 0)
			return (1);
		pthread_detach(state->philo[i].philo_thread);
		i++;
	}
	if (pthread_create(&state->observer_pt, NULL, observer, state) != 0)
		return (1);
	pthread_join(state->observer_pt, NULL);
	return (0);
}