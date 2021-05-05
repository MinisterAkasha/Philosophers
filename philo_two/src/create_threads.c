#include "philo_two.h"

int	create_threads(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->philo_options.p_num)
	{
		if (pthread_create(&state->philo[i].philo_thread, \
			NULL, philo_life_cycle, state) != 0)
			return (1);
		pthread_detach(state->philo[i].philo_thread);
		i++;
	}
	if (pthread_create(&state->observer_pt, NULL, observer, state) != 0)
		return (1);
	pthread_join(state->observer_pt, NULL);
	return (0);
}
