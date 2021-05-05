#include "philo_one.h"

int	main(int argc, char **argv)
{
	t_state	*state;

	if (validate_arguments(argc, argv))
		return (1);
	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (1);
	if (init(state, argv))
		return (exit_error("Error:\nSystem error\n", state));
	if (create_threads(state))
		return (exit_error("Error:\nCan't create threads\n", state));
	free_everything(state);
	printf("End of simulation\n");
	return (0);
}
