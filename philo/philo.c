#include "philo.h"
#include <stdio.h>
int			G_t_eat;

void    my_usleep(uint64_t time)
{
	uint64_t	time_before;

	time_before = get_time();
	usleep((time * TO_MICRO_SEC) - 30000);
	while ((get_time() - time_before) < time)
		continue ;
}

void	*routine(void *param)
{
	int			left;
	int			right;
	uint64_t	time;

	left = *(int *) param;
	right = (left + 1) % state.num_of_philos;
	time = handle_forks(left, right);
	state.philo[left].last_eat = time;
	eat(left, right);
	ft_sleep(left);
	time = get_time();
	out(left, " is thinking", 0, state.g_time);
	if (state.flag == 1)
		routine(param);
	return (EXIT_SUCCESS);
}

int loop(int ac)
{
	int			i;
	uint64_t	time;
	t_bool		flag;
	int		stop_simulation;

	while (true)
	{
		i = -1;
		time = get_time();
		flag = true;
		stop_simulation = controller(ac, i, time, &flag);
		if (stop_simulation == KILL_PROGRAM)
			return (KILL_PROGRAM);
		pthread_mutex_lock(&state.lock);
		if (stop_simulation == true && ac == 6)
			return (KILL_PROGRAM);
		pthread_mutex_unlock(&state.lock);
	}
}

int	main(int ac, const char **av)
{
	int	i;

	if ((ac != 5 && ac != 6) || !init(ac, av))
		exit_error("Fatal error\n");
	i = 1;
	while (i < state.num_of_philos)
	{
		pthread_create(&state.philo[i].pthread,
			NULL, &routine, (void *) &state.philo[i].id);
		i += 2;
	}
	usleep(1e3);
	i = 0;
	while (i < state.num_of_philos)
	{
		pthread_create(&state.philo[i].pthread,
			NULL, &routine, (void *) &state.philo[i].id);
		i += 2;
	}
	if (loop(ac) == KILL_PROGRAM)
		return (EXIT_SUCCESS);
}
