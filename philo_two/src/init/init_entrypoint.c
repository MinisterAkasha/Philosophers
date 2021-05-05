#include "philo_two.h"
#include "structures.h"

int	init(t_state *state, char **argv)
{
	int	error;

	error = 0;
	init_philos_options(&state->philo_options, argv);
	init_start_time(&state->start_time);
	init_semaphores(state, &error);
	init_philosophers(&state->philo, state->philo_options.p_num, \
		state->start_time, &error);
	init_str_message(state->str_message);
	state->philo_pos = 0;
	return (error);
}
