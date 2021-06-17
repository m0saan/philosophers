#include "philo_one.h"

int main(int ac, const char **av)
{
	t_state *state;

	state = NULL;
	if ((ac < 5 || ac > 6) || !init(state, ac, av))
		exit_error("Fatal error\n");
	return (EXIT_SUCCESS);
}
