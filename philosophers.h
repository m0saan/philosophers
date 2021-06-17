#ifndef PHILOSOPHERS_H_H
#define PHILOSOPHERS_H_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
#include <string.h>
# include "utility/utils.h"

typedef struct s_philo
{
	int				id;
	u_int64_t		last_eat;
	int 			total_eat;
	pthread_mutex_t	lock;
	pthread_t		pthread;
}				t_philo;

typedef struct	s_state
{
	int			num_of_philos;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	uint64_t	n_times_must_eat;

	pthread_mutex_t write;
	pthread_mutex_t lock;
	t_philo			*philo;
}				t_state;


#endif
