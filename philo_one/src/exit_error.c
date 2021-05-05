#include "philo_one.h"

int	exit_error(char *error, t_state *state)
{
	ft_putstr_fd("Error:\nCan't init mutex", 2);
	free_everything(state);
	return (1);
}