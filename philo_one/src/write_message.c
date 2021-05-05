#include "write_message.h"
#include "structures.h"
#include "utils.h"

void write_message(t_state *state, int index)
{
	pthread_mutex_lock(&state->message_mutex);
	printf("%ld %d %s", get_current_time(state), index + 1, state->str_message[state->philo[index].state]);
	pthread_mutex_unlock(&state->message_mutex);
}
