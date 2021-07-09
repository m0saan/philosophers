#include "philo.h"

void	eat(int left, int right)
{
	state.philo[left].is_eating = 1;
	out(left, " is eating", 0, state.g_time);
	my_usleep(state.time_to_eat);
	pthread_mutex_unlock(&state.forks[right]);
	pthread_mutex_unlock(&state.forks[left]);
	state.philo[left].is_eating = 0;
}
