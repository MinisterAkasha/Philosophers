#include "philo_two.h"

void	free_everything(t_state *state)
{
	free(state->philo);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_MESSAGE);
	sem_unlink(SEM_PHILO_TAKE_FORKS);
	sem_unlink(SEM_PHILO_POS);
	// sem_close(state->forks_sem);
	// sem_close(state->message_sem);
	// sem_close(state->take_forks_sem);
	// sem_close(state->philo_pos_sem);
	free(state);
}
