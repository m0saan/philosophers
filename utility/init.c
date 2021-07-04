#include "utils.h"

t_bool init_data(int ac, const char **av)
{
	int		i;

	i = 0;
	while(++i < ac)
		if (!is_valid_str_numeric(av[i]))
			return (false);
	state.num_of_philos = ft_atoi(av[1]);
	state.time_to_die = ft_atoi(av[2]);
	state.time_to_eat = ft_atoi(av[3]);
	state.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		state.n_times_must_eat = ft_atoi(av[5]);
	return (true);
}

t_bool init(int ac, const char **av)
{
	int			i;
	uint64_t	time;

	if (!init_data(ac, av))
		return (false);
	pthread_mutex_init(&state.write, NULL);
	pthread_mutex_init(&state.lock, NULL);
	state.philo = malloc(sizeof(t_philo) * state.num_of_philos);
	state.forks = malloc(sizeof(pthread_mutex_t) * state.num_of_philos);
	if (state.philo == NULL)
		return (false);
	i = -1;
	++state.flag;
	time = get_time();
	while(++i < state.num_of_philos)
	{
		state.philo[i].id = i;
		state.philo[i].last_eat = time;
		state.philo[i].total_eat = 0;
		pthread_mutex_init(&state.forks[i], NULL);
	}
	return (true);
}
