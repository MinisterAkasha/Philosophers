#include "write_message.h"
#include "structures.h"
#include "utils.h"

void write_message(t_state *state, int index)
{
	pthread_mutex_lock(&state->message_mutex);
	// printf("%ld %d %s", state->current_time, index + 1, get_message_from_state(state->philo[index].state));
	ft_putnbr_fd(state->current_time, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(index + 1, 1);
	ft_putchar_fd(' ', 1);
	// ft_putstr_fd(get_message_from_state(state->philo[index].state), 1);
	ft_putstr_fd(state->str_message[state->philo[index].state], 1);
	pthread_mutex_unlock(&state->message_mutex);
}
