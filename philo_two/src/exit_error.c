#include "philo_two.h"

int	exit_error(char *error, t_state *state)
{
	ft_putstr_fd(error, 2);
	free_everything(state);
	return (1);
}
