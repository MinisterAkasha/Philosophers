#include "philo_three.h"

void	wait_processes(t_state *state)
{
	int	i;
	int	status;

	i = 0;
	waitpid(0, &status, WUNTRACED);
	if (status % 255 == 1)
	{
		while (i < state->philo_options.p_num)
			kill(state->philo[i++].philo_pid, SIGKILL);
	}
	else if (!status)
		wait_processes(state);
	else if (status % 255 == 2)
		exit_error(THREAD_ERROR, state);
}

int	create_processes(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->philo_options.p_num)
	{
		state->philo_pos = i;
		state->philo[i].philo_pid = fork();
		if (!state->philo[i].philo_pid)
			philo_life_cycle(state);
		else if (state->philo[i].philo_pid < 0)
			exit_error(FORK_ERROR, state);
		i++;
	}
	wait_processes(state);
	return (0);
}
