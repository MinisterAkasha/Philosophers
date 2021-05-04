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
	*philo = (t_philo_state *)malloc(sizeof(t_philo_state) * 1);

	// philo[0]->state = 1;
	// philo[1]->state = 2;
	// philo[2]->state = 3;
}

int	init(t_state *state, char **argv)
{
	state->error = 0;
	init_philos_options(&state->philo_options, argv);
	init_start_time(&state->start_time);
	init_forks(&state->forks, state->philo_options.p_num, &state->error);
	init_philosophers(&state->philo, state->philo_options.p_num);
	return (state->error);
}
