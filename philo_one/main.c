#include "philo_one.h"

int	main(int argc, char **argv)
{
	t_state *state;

	if (validate_arguments(argc, argv))
		return (1);
	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (1);
	if (init(state, argv))
	{
		ft_putstr_fd("Error:\nCan't init mutex", 2);
		free_everything(state);
		return (1);
	}
	if (create_threads(state))
	{
		ft_putstr_fd("Error:\nCan't create threads", 2);
		free_everything(state);
		return (1);
	}
	free_everything(state);
	ft_putstr_fd("End of simulation\n", 1);
	return (0);
}