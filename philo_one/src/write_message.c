#include "write_message.h"
#include "structures.h"
#include "utils.h"

char *get_message_from_state(int state)
{
	if (state == IS_EATING)
		return ("is eating\n");
	else if (state == IS_THINKING)
		return ("is thinking\n");
	else if (state == IS_SLEEPING)
		return ("is sleeping\n");
	else if (state == IS_DEAD)
		return ("died\n");
	else if (state == IS_TAKE_FORK)
		return ("has taken a fork\n");
	return ("UNKNNOWN STATE!!!!\n");
}

void write_message(t_state *state, int index)
{
	pthread_mutex_lock(&state->message_mutex);
	ft_putnbr_fd(state->current_time, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(index + 1, 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(get_message_from_state(state->philo[index].state), 1);
	pthread_mutex_unlock(&state->message_mutex);
}
