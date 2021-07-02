#include "utils.h"

int		exit_error(char const *str)
{
	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

t_bool is_valid_str_numeric(const char *arg)
{
	int i;

	i = -1;
	while(arg[++i])
		if (!ft_isdigit(arg[i]))
			return (false);
	return (true);
}

uint64_t get_time()
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	/*
	 * tv_sec // seconds since Jan. 1, 1970.
	 * tv_usec // and microseconds.
	 */
	return (time.tv_sec * 1000);
}
