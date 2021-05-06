#include "philo_two.h"
#include "structures.h"

int	init(t_state *state, char **argv)
{
	state->error_code = -1;
	init_philos_options(&state->philo_options, argv);
	init_start_time(&state->start_time);
	init_semaphores(state, &state->error_code);
	init_philosophers(&state->philo, state->philo_options.p_num, \
		state->start_time, &state->error_code);
	init_str_message(state->str_message);
	state->philo_pos = 0;
	return (state->error_code);
}
