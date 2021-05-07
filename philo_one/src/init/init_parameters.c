#include "philo_one.h"
#include "structures.h"

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

void	init_mutex(t_state *state, int forks_num, int *error)
{
	int	i;

	i = 0;
	state->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
		* (forks_num));
	if (!state->forks)
	{
		*error = MALLOC_ERROR;
		return ;
	}
	while (i < forks_num)
	{
		if (pthread_mutex_init(&(state->forks[i]), NULL) != 0)
			*error = MUTEX_ERROR;
		i++;
	}
	if (pthread_mutex_init(&state->message_mutex, NULL) != 0)
		*error = MUTEX_ERROR;
	if (pthread_mutex_init(&state->philo_pos_mutex, NULL) != 0)
		*error = MUTEX_ERROR;
}

void	init_philosophers(t_philo_state **philo, int philo_num, int *error)
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
