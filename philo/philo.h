#ifndef PHILO_ONE_H
#define PHILO_ONE_H

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "utility/utils.h"

#define TO_MICRO_SEC 1000
#define KILL_PROGRAM (-1)

uint64_t	lock_and_output(int current_philo_index);
void		eat(int left, int right);
void		ft_sleep(int left);
t_bool		controller(int ac, int i, uint64_t time, t_bool *flag);
void	eat(int left, int right);
void	ft_sleep(int left);
t_bool	controller(int ac, int i, uint64_t time, t_bool *flag);
uint64_t	handle_forks(int l, int r);

#endif
