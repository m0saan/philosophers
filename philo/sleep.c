#include "philo.h"

void ft_sleep(int left, t_state *state)
{
	out(left, " is sleeping", 0, state);
	my_usleep(state->time_to_sleep);
}
