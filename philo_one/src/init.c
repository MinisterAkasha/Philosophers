#include "philo_one.h"

static void	init_philos_options(t_philos_options *philo_options, char **argv)
{
	philo_options->p_num = ft_atoi(argv[1]);
	philo_options->time_to_die = ft_atoi(argv[2]);
	philo_options->time_to_eat = ft_atoi(argv[3]);
	philo_options->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo_options->times_need_to_eat = ft_atoi(argv[5]);
	else
		philo_options->times_need_to_eat = -1;
}

static void	init_start_time(int *start_time)
{
	struct timeval	tv;
	struct timezone	tz;

	gettimeofday(&tv, &tz);
	*start_time = tv.tv_usec;
}

static void	init_forks(pthread_mutex_t **forks, int forks_num, int *error)
{
	int i;

	i = 0;
	*forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (forks_num));
	while (i < forks_num)
	{
		if (pthread_mutex_init(&((*forks)[i]), NULL) != 0)
			*error = 1;
		i++;
	}
}

static void init_philosophers(t_philo_state **philo, int philo_num)
{
	int	i;

	i = 0;
	*philo = (t_philo_state *)malloc(sizeof(t_philo_state) * 1);
	while (i < philo_num)
	{
		(*philo)[i].position = i;
		(*philo)[i].state = IS_THINKING;
		i++;
	}
}

int	init(t_state *state, char **argv)
{
	int	error;
	error = 0;
	init_philos_options(&state->philo_options, argv);
	init_start_time(&state->start_time);
	init_forks(&state->forks, state->philo_options.p_num, &error);
	init_philosophers(&state->philo, state->philo_options.p_num);
	if (pthread_mutex_init(&state->message_mutex, NULL) != 0)
		error = 1;
	if (pthread_mutex_init(&state->philo_pos_mutex, NULL) != 0)
		error = 1;
	return (error);
}
