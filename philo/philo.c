#include "philo.h"
#include <stdio.h>

void	my_usleep(uint64_t time)
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
	t_state		*state;
	t_philo		*philo;

	philo = (t_philo*)param;
	state = philo->state;
	left = philo->index;
	right = (left + 1) % state->num_of_philos;
	handle_forks(left, right, state);
	philo->last_eat = get_time();
	eat(left, right, philo);
	ft_sleep(left, state);
	out(left, " is thinking", 0, state);
	if (state->flag == 1)
		routine(param);
	return (EXIT_SUCCESS);
}

int loop(int ac, t_philo *philo)
{
	t_bool		flag;
	int			stop_simulation;

	while (true)
	{
		flag = true;
		stop_simulation = controller(ac, &flag, philo);
		if (stop_simulation == KILL_PROGRAM)
			return (KILL_PROGRAM);
		pthread_mutex_lock(&philo[0].state->lock);
		if (stop_simulation == true && ac == 6)
			return (KILL_PROGRAM);
		pthread_mutex_unlock(&philo[0].state->lock);
	}
}

int	main(int ac, const char **av)
{
	int	i;

	t_philo *philo;
	t_state *state;

	state = malloc(sizeof(t_state));
	if ((ac != 5 && ac != 6) || !init(ac, av, state, &philo))
		p_error("Fatal error\n");
	if (state->n_times_must_eat != NO_EAT)
	{
		i = 0;
		while (i < state->num_of_philos)
		{
			philo[i].index = i;
			// &state.philo[i].id
			pthread_create(&philo[i].pthread,
						   NULL, &routine, (void *) &philo[i]);
			i += 2;
		}
		usleep(1e3);
		i = 1;
		while (i < state->num_of_philos)
		{
			philo[i].index = i;
			pthread_create(&philo[i].pthread,
						   NULL, &routine, (void *) &philo[i]);
			i += 2;
		}
		loop(ac, philo);
	}
}
