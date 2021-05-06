#include "philo_three.h"

int	main(int argc, char **argv)
{
	t_state	*state;

	if (validate_arguments(argc, argv))
		return (1);
	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		exit_error(MALLOC_ERROR, state);
	if (init(state, argv) != -1)
		exit_error(state->error_code, state);
	if (create_processes(state))
		exit_error(state->error_code, state);
	free_everything(state);
	printf("End of simulation\n");
	return (0);
}
