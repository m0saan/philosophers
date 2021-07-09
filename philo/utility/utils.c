#include "utils.h"

int	exit_error(char const *str)
{
	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

t_bool	is_valid_str_numeric(const char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (!ft_isdigit(arg[i]))
			return (false);
	return (true);
}

uint64_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	out(int action, const char *msg, uint8_t is_dead, uint64_t g_time)
{
	pthread_mutex_lock(&state.write);
	printf("%llu %d %s\n", get_time() - g_time, action + 1, msg);
	if (!is_dead)
		pthread_mutex_unlock(&state.write);
}

uint64_t	lock_and_output(int current_philo_index)
{
	uint64_t	time;

	time = get_time();
	out(current_philo_index, " has taken a fork", 0, state.g_time);
	return (time);
}
