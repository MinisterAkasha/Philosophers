#include "philo_one.h"

// void* plus(void *args)
// {
// 	t_state *state;

// 	state = (t_state*) args;
// 	pthread_mutex_lock(&state->forks[0]);
// 	for (int i = 0; i < 20; i++)
// 	pthread_mutex_unlock(&state->forks[0]);
// 	return (NULL);
// }


int	main(int argc, char **argv)
{
	t_state *state;
	pthread_t philos[2];

	if (validate_arguments(argc, argv))
		return (1);
	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (1);
	init(state, argv);
	if (state->error)
		ft_putstr_fd("Error:\nSystem error", 2);

	// int status;
	// status = pthread_create(&philos[0], NULL, plus, state);

	free_everything(state);
	return (0);
}