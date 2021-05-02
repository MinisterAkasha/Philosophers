#include "philo_one.h"

void	init_philos_options(t_philos_options *philos, char **argv)
{
	philos->p_num = ft_atoi(argv[1]);
	philos->time_to_die = ft_atoi(argv[2]);
	philos->time_to_eat = ft_atoi(argv[3]);
	philos->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philos->times_need_to_eat = ft_atoi(argv[5]);
	else
		philos->times_need_to_eat = -1;
}