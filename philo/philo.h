#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include "utility/utils.h"

# define TO_MICRO_SEC 1000
# define KILL_PROGRAM (-1)

void		eat(int left, int right);
void		ft_sleep(int left);
t_bool		controller(int ac, int i, uint64_t time, t_bool *flag);
uint64_t	handle_forks(int l, int r);
void		my_usleep(uint64_t time);

#endif
