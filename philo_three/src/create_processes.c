#include "philo_three.h"

void	wait_processes(t_state *state)
{
	int i;
	int status;

	i = 0;
	waitpid(0, &status, WUNTRACED);
	if (!status)
		wait_processes(state);
	else
	{
		while (i < state->philo_options.p_num)
			kill(state->philo[i++].philo_pid, SIGKILL);
	}
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
		if (state->philo[i].philo_pid < 0)//TODO add error
			return (1);
		i++;
	}
	wait_processes(state);
	return (0);
}
