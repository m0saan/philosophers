#include "philo.h"
#include "utility/utils.h"

t_bool	controller(int ac, t_bool *flag, t_philo *philo)
{
	t_bool	stop_simulation;
	int		i;
	int		num_of_philos;

	stop_simulation = false;
	i = -1;
	num_of_philos = philo[0].state->num_of_philos;
	while (++i < num_of_philos)
	{
		if (philo[i].is_eating && philo[i].state->num_of_philos != 1)
			continue ;
		if (ac == 6 && (*flag) && (philo[i].total_eat / \
		philo[i].state->time_to_eat) > philo[i].state->n_times_must_eat)
		{
			(*flag) = false;
			stop_simulation = true;
			return (KILL_PROGRAM);
		}
		if (get_time() > philo[i].last_eat + philo[i].state->time_to_die)
		{
			out(i, "died", 1, philo[i].state);
			return (KILL_PROGRAM);
		}
	}
	return (stop_simulation);
}

uint64_t	handle_forks(int l, int r, t_state *state)
{
	pthread_mutex_lock(&state->forks[r]);
	pthread_mutex_lock(&state->forks[l]);
	lock_and_output(l, state);
	lock_and_output(l, state);
	return (0);
}
