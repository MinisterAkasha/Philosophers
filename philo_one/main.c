#include "philo_one.h"

int	main(int argc, char **argv)
{
	t_state *state;

	if (validate_arguments(argc, argv))
		return (1);
	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (1);
	init(state, argv);
	if (state->error == 1)
		ft_putstr_fd("Error:\nCan't init mutex", 2);
	create_threads(state);
	free_everything(state);
	return (0);
}