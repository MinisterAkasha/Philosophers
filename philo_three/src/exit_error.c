#include "philo_three.h"

char	*get_error_string(int error_code)
{
	if (error_code == MALLOC_ERROR)
		return ("Malloc error\n");
	else if (error_code == SEMAPHORE_ERROR)
		return ("Semaphore error\n");
	else if (error_code == THREAD_ERROR)
		return ("Thread error\n");
	else if (error_code == FORK_ERROR)
		return ("Fork error\n");
	return ("Unknown error\n");
}

void	exit_error(int error_code, t_state *state)
{
	ft_putstr_fd(get_error_string(error_code), 2);
	if (state)
		free_everything(state);
	exit(error_code);
}
