#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <semaphore.h>

typedef enum e_Bool {
	FALSE,
	TRUE
}	t_Bool;

typedef enum e_state_type {
	IS_TAKE_FORK,
	IS_EATING,
	IS_THINKING,
	IS_SLEEPING,
	IS_DEAD
}	t_state_type;

typedef enum e_error_codes {
	MALLOC_ERROR,
	SEMAPHORE_ERROR,
	THREAD_ERROR
}	t_error_codes;

typedef struct s_philos_options {
	int			p_num;
	long int	time_to_die;
	long int	time_to_eat;
	long int	time_to_sleep;
	long int	times_need_eat;
}				t_philos_options;

typedef struct s_philo_state {
	int			state;
	int			position;
	int			eat_times;
	int			last_eat;
	pthread_t	philo_thread;
}				t_philo_state;

typedef struct s_state {
	long				start_time;

	t_philos_options	philo_options;
	t_philo_state		*philo;

	sem_t				*forks_sem;
	sem_t				*take_forks_sem;
	sem_t				*message_sem;
	sem_t				*philo_pos_sem;

	pthread_t			observer_pt;

	char				*str_message[5];
	int					philo_pos;

	int					error_code;
	int					*eaten_philos;
}				t_state;

#endif