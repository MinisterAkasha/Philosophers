#include "philo_one.h"

//? gcc -I Includes/ main.c src/utils.c -o philo_one src/validate_arguments.c src/init.c

int	main(int argc, char **argv)
{
	t_philos_options philos;

	if (validate_arguments(argc, argv))
		return (1);
	init_philos_options(&philos, argv);
	printf("%d\n%d\n%d\n%d\n%d", philos.p_num, philos.time_to_die, philos.time_to_eat, philos.time_to_sleep, philos.times_need_to_eat);
	return (0);
}