#ifndef PHILOSOPHERS_H_H
#define PHILOSOPHERS_H_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# define	NO_EAT (0)

typedef struct	s_state
{
	int			num_of_philos;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	uint64_t	n_times_must_eat;
	uint64_t	g_time;


	pthread_mutex_t write;
	pthread_mutex_t lock;
	pthread_mutex_t *forks;
	int 			flag;
}				t_state;

typedef struct s_philo
{
	int				id;
	u_int64_t		last_eat;
	uint64_t 		total_eat;
	pthread_t		pthread;
	uint8_t 		is_eating;
	t_state			*state;
	int 			index;
}				t_philo;

#endif
