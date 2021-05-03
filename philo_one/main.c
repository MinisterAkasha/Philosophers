#include "philo_one.h"

int	main(int argc, char **argv)
{
	t_state *state;

	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (1);
	if (!validate_arguments(argc, argv))
		init(state, argv);
	if (state->error)
		ft_putstr_fd("Error:\nSystem error", 2);
	free_everything(state);
	return (0);
}