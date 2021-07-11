#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include "../../philosophers.h"

typedef enum e_bool
{
	false = 0,
	true = 1,
}			t_bool;

void p_error(char const *str);
t_bool init(int ac, const char **av, t_state *state, t_philo **philo);
t_bool init_data(int ac, const char **av, t_state *state);
t_bool		is_valid_str_numeric(const char *arg);
uint64_t	get_time(void);
size_t		ft_strlen(const char *str);
int			ft_isdigit(int c);
int			ft_atoi(const char *s);
void out(int action, const char *msg, uint8_t is_dead, t_state *state);
uint64_t lock_and_output(int current_philo_index, t_state *state);

#endif
