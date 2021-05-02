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
	struct timeval tv;
	struct timezone tz;

	gettimeofday(&tv, &tz);
	*start_time = tv.tv_usec;
	// printf("Секунды: %ld\nМикросекунды: %d", tv.tv_sec, tv.tv_usec);
}

void	init(t_state *state, char **argv)
{
	init_philos_options(&state->philo_options, argv);

	init_start_time(&state->start_time);
}