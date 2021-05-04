#include "philo_one.h"

int a;

void* observer(void *args)
{
	t_state *state;

	state = (t_state*) args;
	while (1)
	{

	}
	return (NULL);
}

void* philo_life_cycle(void *args)
{
	t_state *state;

	state = (t_state*) args;
	pthread_mutex_lock(&state->forks[0]);
	for (int i = 0; i < 20; i++)
		a++;
	pthread_mutex_unlock(&state->forks[0]);
	return (NULL);
}

int create_threads(t_state *state)
{
	int status;
	int i;

	i = 0;
	while (i < state->philo_options.p_num)
	{
		//TODO обработать ошибки
		status = pthread_create(&state->philo[i].philo_thread, NULL, philo_life_cycle, state);
		if (status != 0)
			return (1);
		pthread_detach(state->philo[i].philo_thread);
		i++;
	}
	status = pthread_create(&state->observer_pt, NULL, observer, state);
	if (status != 0)
		return (1);
	pthread_join(state->observer_pt, NULL);
	return (0);
}