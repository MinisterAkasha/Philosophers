#include "philo_one.h"
#include "structures.h"

void	ini_eaten_philos_arr(t_state *state, int philo_num, int *error)
{
	int	i;

	i = 0;
	state->eaten_philos = (int *)malloc(sizeof(int) * (philo_num));
	if (!state->eaten_philos)
	{
		*error = MALLOC_ERROR;
		return ;
	}
	while (i < philo_num)
		state->eaten_philos[i++] = FALSE;
}

int	init(t_state *state, char **argv)
{
	state->error_code = -1;
	init_philos_options(&state->philo_options, argv);
	init_start_time(&state->start_time);
	init_mutex(state, state->philo_options.p_num, &state->error_code);
	init_philosophers(&state->philo, state->philo_options.p_num, \
		 &state->error_code);
	init_eaten_philos_arr(state, state->philo_options.p_num, \
		&state->error_code);
	init_str_message(state->str_message);
	state->philo_pos = 0;
	return (state->error_code);
}
