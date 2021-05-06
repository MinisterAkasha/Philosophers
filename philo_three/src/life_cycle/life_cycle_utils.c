#include "philo_three.h"

int	get_philo_pos(t_state *state)
{
	int	pos;

	sem_wait(state->philo_pos_sem);
	pos = state->philo_pos++;
	sem_post(state->philo_pos_sem);
	return (pos);
}

void	get_forks_index(int pos, int philo_num, int (*forks)[2])
{
	(*forks)[0] = pos;
	if (pos == philo_num - 1)
		(*forks)[1] = 0;
	else
		(*forks)[1] = pos + 1;
}
