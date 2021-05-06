#include "write_message.h"
#include "structures.h"
#include "utils.h"

void	write_message(t_state *state, int index)
{
	sem_wait(state->message_sem);
	ft_putnbr_fd(get_current_time(state), 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(index + 1, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(state->str_message[state->philo[index].state], 1);
	sem_post(state->message_sem);
}
