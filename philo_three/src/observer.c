#include "philo_three.h"

void	*observer(void *args)
{
	t_state	*state;

	state = (t_state *) args;
	while (TRUE)
	{
		if (get_current_time(state) - state->philo[state->philo_pos].last_eat \
			> state->philo_options.time_to_die)
		{
			sem_wait(state->message_sem);
			sem_wait(state->dead_philo_sem);
			state->philo[state->philo_pos].state = IS_DEAD;
			printf("%ld %d %s", get_current_time(state), \
			state->philo_pos + 1, \
			state->str_message[state->philo[state->philo_pos].state]);
			exit(1);
		}
	}
	return (NULL);
}
