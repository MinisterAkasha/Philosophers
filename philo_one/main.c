#include "philo_one.h"

//? gcc -I Includes/ main.c src/utils.c -o philo_one src/validate_arguments.c src/init.c

int	main(int argc, char **argv)
{
	t_state *state;

	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (1);
	if (validate_arguments(argc, argv))
		return (1);
	init(state, argv);
	printf("%d\n%d\n%d\n%d\n%d\n", state->philo_options.p_num, state->philo_options.time_to_die, state->philo_options.time_to_eat, state->philo_options.time_to_sleep, state->philo_options.times_need_to_eat);
	printf("START TIME: %d\n", state->start_time);
	free(state);
	return (0);
}