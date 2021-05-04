#ifndef WRITE_MESSAGE_H
# define WRITE_MESSAGE_H

# include <pthread.h>
# include "structures.h"

void write_message(t_state *state, int index);
char *get_message_from_state(int state);

#endif