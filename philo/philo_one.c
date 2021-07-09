#include "philo_one.h"
#include <stdio.h>

uint64_t g_time;

void out(int action, const char *msg, uint8_t is_dead) {
	pthread_mutex_lock(&state.write);
	printf("%llu %d %s\n", get_time() - g_time, action + 1, msg);
	if(!is_dead)
		pthread_mutex_unlock(&state.write);
}

uint64_t lock_and_output(int current_philo_index) {
	uint64_t time;

	time = get_time();
    out(current_philo_index, " has taken a fork", 0);
	return (time);
}

uint64_t handle_forks(int l, int r) {
	uint64_t time;
	pthread_mutex_lock(&state.forks[l]);
	pthread_mutex_lock(&state.forks[r]);
    lock_and_output(l);
	time = lock_and_output(l);
	return (time);

}

void my_usleep(uint64_t time) {
	uint64_t time_before;

	time_before = get_time();
	usleep((time * TO_MICRO_SEC) - 30000);
	while((get_time() - time_before) < time)
		continue;
}

void *routine(void *param)
{
	int left;
	int right;
	unsigned long long time;


	left = *(int *) param;

	right = (left + 1) % state.num_of_philos;
	/*
	 * Taking a fork
	 */
	time = handle_forks(left, right);
	state.philo[left].last_eat = time;

	/*
	 * Start eating
	 */
	state.philo[left].is_eating = 1;
    out(left, " is eating", 0);
	my_usleep(state.time_to_eat);

	pthread_mutex_unlock(&state.forks[right]);
	pthread_mutex_unlock(&state.forks[left]);
	state.philo[left].is_eating = 0;

	/*
	 * Start sleeping
	 */
	time = get_time();
	state.philo[left].total_eat += (int) state.time_to_eat;
    out(left, " is sleeping", 0);
	my_usleep(state.time_to_sleep);

	/*
	 * Start thinking
	 */
	time = get_time();
    out(left, " is thinking", 0);

	if(state.flag == 1)
		routine(param);
	return (EXIT_SUCCESS);
}

_Noreturn void loop(int ac)
{
	int i;
	uint64_t time;
	t_bool flag;
	t_bool stop_simulation;

	while(true)
	{
		i = -1;
		time = get_time();
		flag = true;
		stop_simulation = false;
		while(++i < state.num_of_philos)
		{
			if (state.philo[i].is_eating)
				continue;
			if (ac == 6 && flag && (state.philo[i].total_eat / state.time_to_eat) > state.n_times_must_eat)
			{
                flag = false;
                stop_simulation = true;
            }
			if (time > state.philo[i].last_eat + state.time_to_die)
			{
                out(i, "died", 1);
				exit(EXIT_SUCCESS);
			}
		}
        pthread_mutex_lock(&state.lock);
		if (stop_simulation && ac == 6)
            exit(EXIT_SUCCESS);
        pthread_mutex_unlock(&state.lock);
	}
}

int main(int ac, const char **av) {
	int i;

	g_time = get_time();
	if((ac != 5 && ac != 6) || !init(ac, av))
		exit_error("Fatal error\n");
	i = 1;
	while(i < state.num_of_philos) {
		pthread_create(&state.philo[i].pthread, NULL, &routine, (void *) &state.philo[i].id);
		i += 2;
	}
	usleep(1e3);
	i = 0;
	while(i < state.num_of_philos) {
		pthread_create(&state.philo[i].pthread, NULL, &routine, (void *) &state.philo[i].id);
		i += 2;
	}

	loop(ac);
}
