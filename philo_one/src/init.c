#include "philo_one.h"
#include "structures.h"

static void	init_philos_options(t_philos_options *philo_options, char **argv)
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

static void	init_start_time(long *start_time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	*start_time = tv.tv_sec * 1000 + (long)(tv.tv_usec / 1000);
}

static void	init_mutex(pthread_mutex_t **forks, int forks_num, int *error)
{
	int	i;

	i = 0;
	*forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (forks_num));
	while (i < forks_num)
	{
		if (pthread_mutex_init(&((*forks)[i]), NULL) != 0)
			*error = 1;
		i++;
	}
}

static void	init_philosophers(t_philo_state **philo, int philo_num, \
	int start_time)
{
	int	i;

	i = 0;
	*philo = (t_philo_state *)malloc(sizeof(t_philo_state) * 1);
	while (i < philo_num)
	{
		(*philo)[i].position = i;
		(*philo)[i].eat_times = 0;
		(*philo)[i].last_eat = 0;
		i++;
	}
}

static void	init_str_message(char *str_message[5])
{
	str_message[IS_TAKE_FORK] = "has taken a fork\n";
	str_message[IS_EATING] = "is eating\n";
	str_message[IS_THINKING] = "is thinking\n";
	str_message[IS_SLEEPING] = "is sleeping\n";
	str_message[IS_DEAD] = "died\n";
}

int	init(t_state *state, char **argv)
{
	int	error;

	error = 0;
	init_philos_options(&state->philo_options, argv);
	init_start_time(&state->start_time);
	init_mutex(state, state->philo_options.p_num, &error);
	init_philosophers(&state->philo, state->philo_options.p_num, \
		state->start_time);
	if (pthread_mutex_init(&state->message_mutex, NULL) != 0)
		error = 1;
	if (pthread_mutex_init(&state->philo_pos_mutex, NULL) != 0)
		error = 1;
	state->philo_pos = 0;
	init_str_message(state->str_message);
	return (error);
}
