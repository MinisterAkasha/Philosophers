#include "philo_two.h"

char	*get_error_string(int error_code)
{
	if (error_code == MALLOC_ERROR)
		return ("Malloc error\n");
	else if (error_code == SEMAPHORE_ERROR)
		return ("Semaphore error\n");
	else if (error_code == THREAD_ERROR)
		return ("Thread error\n");
	return ("Unknown error\n");
}

int	exit_error(int error_code, t_state *state)
{
	ft_putstr_fd(get_error_string(error_code), 2);
	if (state)
		free_everything(state);
	return (1);
}
