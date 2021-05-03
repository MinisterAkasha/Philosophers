#include "philo_one.h"

void free_forks(pthread_mutex_t *forks, int forks_num)
{
	int i;

	i = 0;
	while (i < forks_num)
		pthread_mutex_destroy(&forks[i++]);
	free(forks);
}

void free_everything(t_state *state)
{
	free_forks(state->forks, state->philo_options.p_num);
	free(state);
}

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