#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include "utility/utils.h"

# define TO_MICRO_SEC 1000
# define KILL_PROGRAM (-1)

void eat(int left, int right, t_philo *philo);
void ft_sleep(int left, t_state *state);
t_bool controller(int ac, t_bool *flag, t_philo *philo);
uint64_t handle_forks(int l, int r, t_state *state);
void		my_usleep(uint64_t time);

#endif
