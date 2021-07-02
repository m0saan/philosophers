#include "philo_one.h"
#include <stdio.h>

void	out(t_philo *philo, uint64_t time, int action, const char *msg)
{
	pthread_mutex_lock(&state.write);
	printf("%llu %d %s\n", get_time() - philo->start, action + 1, msg);
	pthread_mutex_unlock(&state.write);
}

void lock_and_output(int act, int which) {
	uint64_t time;

	pthread_mutex_lock(&state.philo[which].lock);
	time = get_time();
	out(&state.philo[which], time, act, " has taken a fork");
}

uint64_t handle_forks(int l, int r)
{
	uint64_t time;

	pthread_mutex_lock(&state.lock);    // lock.
	pthread_mutex_lock(&state.philo[r].lock);
	time = get_time();
	out(&state.philo[l], time, l, " has taken a fork");
	pthread_mutex_lock(&state.philo[l].lock);
	time = get_time();
	out(&state.philo[l], time, l, " has taken a fork");
	printf("forks: [%d-%d]\n", l, r);
	pthread_mutex_unlock(&state.lock); // unlock.
	return (time);

}

void *routine(void *param)
{
	int					left;
	int					right;
	unsigned long long	time;

	left = *(int*)param;

	right = left - 1;
	if (right == -1)
		right = state.num_of_philos - 1;
	/*
	 * Taking a fork
	 */
	time = handle_forks(left, right);
	state.philo[left].last_eat = time;

	/*
	 * Start eating
	 */
	out(&state.philo[left], time, left , " is eating");
	usleep(state.time_to_eat * TO_MICRO_SEC);

	/*
	 * Start sleeping
	 */
	time = get_time();
	state.philo[left].total_eat += (int )state.time_to_eat;
	out(&state.philo[left], time, left , " is sleeping");
	pthread_mutex_unlock(&state.philo[right].lock);
	pthread_mutex_unlock(&state.philo[left].lock);
	usleep(state.time_to_sleep * TO_MICRO_SEC);

	/*
	 * Start thinking
	 */
	time = get_time();
	out(&state.philo[left], time, left, " is thinking");

	if (state.flag == 1)
		routine(param);
	return (EXIT_SUCCESS);
}

_Noreturn void loop(int ac) {
	int i;
	uint64_t time;
	t_bool flag;

	while(true)
	{
		i = -1;
		time = get_time();
		flag = true;
		while(++i < state.num_of_philos)
		{
			if (ac == 6 && flag && state.philo[i].total_eat < state.n_times_must_eat)
				flag = false;
			if (time > state.philo[i].last_eat + state.time_to_die)
			{
				out(&state.philo[i], time, i, "died");
				exit(EXIT_SUCCESS);
			}
		}
		pthread_mutex_lock(&state.lock);
		if (ac == 6 && flag == 1)
			exit(EXIT_SUCCESS);
		pthread_mutex_unlock(&state.lock);
	}
}

int main(int ac, const char **av) {
	int		i;

	i = -1;
	if((ac != 5 && ac != 6) || !init(ac, av))
		exit_error("Fatal error\n");
	while (++i < state.num_of_philos)
		pthread_create(&state.philo[i].pthread, NULL, &routine, (void *)&state.philo[i].id);

	loop(ac);
}
