#include "philo_one.h"

void update_current_time(t_state **state)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	(*state)->current_time = (tv.tv_sec * 1000 + tv.tv_usec / 1000) - (*state)->start_time;
}

int check_is_philo_dead(t_philo_state philo, long time_to_die, long start_time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - start_time - philo.last_eat > time_to_die)
		return (1);
	return (0);
}

int check_has_every_philo_eaten(t_state *state)
{
	int i;

	i = 0;
	while (i < state->philo_options.p_num)
	{
		if (state->philo[i].eat_times != state->philo_options.times_need_to_eat)
			return (0);
		i++;
	}
	return (1);
}

void* observer(void *args)
{
	t_state *state;
	int		i;

	state = (t_state*) args;
	while (TRUE)
	{
		i = 0;
		while (i < state->philo_options.p_num)
		{
			update_current_time(&state);
			if (state->philo_options.times_need_to_eat != -1 && check_has_every_philo_eaten(state))
				return (NULL);
			if (check_is_philo_dead(state->philo[i], state->philo_options.time_to_die, state->start_time))
			{
				state->philo[i].state = IS_DEAD;
				write_message(state, i);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
