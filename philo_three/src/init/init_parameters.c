#include "philo_three.h"
#include "structures.h"

void	init_semaphores(t_state *state, int *error)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_MESSAGE);
	sem_unlink(SEM_PHILO_TAKE_FORKS);
	sem_unlink(SEM_PHILO_POS);
	sem_unlink(SEM_DEAD_PHILO);
	state->forks_sem = sem_open(SEM_FORKS, O_CREAT | O_EXCL, \
		0600, state->philo_options.p_num);
	state->message_sem = sem_open(SEM_MESSAGE, O_CREAT | O_EXCL, 0600, 1);
	state->philo_pos_sem = sem_open(SEM_PHILO_POS, O_CREAT | O_EXCL, 0600, 1);
	state->take_forks_sem = sem_open(SEM_PHILO_TAKE_FORKS, O_CREAT | O_EXCL, \
		0600, 1);
	state->dead_philo_sem = sem_open(SEM_DEAD_PHILO, O_CREAT | O_EXCL, \
		0600, 1);
	if (state->forks_sem == SEM_FAILED || state->message_sem == SEM_FAILED \
		|| state->philo_pos_sem == SEM_FAILED \
		|| state->take_forks_sem == SEM_FAILED \
		|| state->dead_philo_sem == SEM_FAILED)
		*error = SEMAPHORE_ERROR;
}

void	init_philos_options(t_philos_options *philo_options, char **argv)
{
	philo_options->p_num = ft_atoi(argv[1]);
	philo_options->time_to_die = ft_atoi(argv[2]);
	philo_options->time_to_eat = ft_atoi(argv[3]);
	philo_options->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo_options->times_need_eat = ft_atoi(argv[5]);
	else
		philo_options->times_need_eat = -1;
}

void	init_start_time(long *start_time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	*start_time = tv.tv_sec * 1000 + (long)(tv.tv_usec / 1000);
}

void	init_philosophers(t_philo_state **philo, int philo_num, \
	int start_time, int *error)
{
	int	i;

	i = 0;
	*philo = (t_philo_state *)malloc(sizeof(t_philo_state) * philo_num);
	if (!philo)
	{
		*error = MALLOC_ERROR;
		return ;
	}
	while (i < philo_num)
	{
		(*philo)[i].position = i;
		(*philo)[i].eat_times = 0;
		(*philo)[i].last_eat = 0;
		i++;
	}
}

void	init_str_message(char *str_message[5])
{
	str_message[IS_TAKE_FORK] = "has taken a fork\n";
	str_message[IS_EATING] = "is eating\n";
	str_message[IS_THINKING] = "is thinking\n";
	str_message[IS_SLEEPING] = "is sleeping\n";
	str_message[IS_DEAD] = "died\n";
}
