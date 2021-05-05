#include "philo_one.h"

int get_dead_philo_index(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->philo_options.p_num)
	{
		if (get_current_time(state) - state->philo[i].last_eat > state->philo_options.time_to_die)
			return (i);
		i++;
	}
	return (-1);
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
	int		dead_philo_index;

	dead_philo_index = -1;
	state = (t_state*) args;
	while (TRUE)
	{

		if (state->philo_options.times_need_to_eat != -1 && check_has_every_philo_eaten(state))
			return (NULL);
		
		dead_philo_index = get_dead_philo_index(state);
		if (dead_philo_index != -1)
		{
			state->philo[dead_philo_index].state = IS_DEAD;
			write_message(state, dead_philo_index);
			return (NULL);
		}
	}
	return (NULL);
}
