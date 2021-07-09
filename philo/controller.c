#include "philo.h"
#include "utility/utils.h"

t_bool	controller(int ac, int i, uint64_t time, t_bool *flag)
{
	t_bool	stop_simulation;

	stop_simulation = false;
	while (++i < state.num_of_philos)
	{
		if (state.philo[i].is_eating)
			continue ;
		if (ac == 6 && (*flag) && (state.philo[i].total_eat / \
		state.time_to_eat) > state.n_times_must_eat)
		{
			(*flag) = false;
			stop_simulation = true;
		}
		if (time > state.philo[i].last_eat + state.time_to_die)
		{
			out(i, "died", 1, state.g_time);
			return (KILL_PROGRAM);
		}
	}
	return (stop_simulation);
}

uint64_t	handle_forks(int l, int r)
{
	uint64_t	time;

	pthread_mutex_lock(&state.forks[l]);
	pthread_mutex_lock(&state.forks[r]);
	lock_and_output(l);
	time = lock_and_output(l);
	return (time);
}