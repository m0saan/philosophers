#include "philo.h"

void	ft_sleep(int left)
{
	uint64_t	time;

	time = get_time();
	state.philo[left].total_eat += (int) state.time_to_eat;
	out(left, " is sleeping", 0, state.g_time);
	my_usleep(state.time_to_sleep);
}