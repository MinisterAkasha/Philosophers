#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <pthread.h>

typedef enum e_Bool {
	FALSE,
	TRUE
}	t_Bool;

typedef enum e_state_type {
	EATING,
	THINKING,
	SLEEPING,
	IS_DEAD
}	t_state_type;

typedef struct s_philos_options {
	int	p_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_need_to_eat;
}				t_philos_options;

typedef struct s_philo_state {
	int			state;
	int			position;
	pthread_t	philo_thread;
}				t_philo_state;

typedef struct s_state {
	int					start_time;
	t_philo_state		*philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		message_mutex;
	pthread_t			observer_pt;

	int					error;
	t_philos_options	philo_options;
}				t_state;

#endif