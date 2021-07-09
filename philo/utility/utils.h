//
// Created by moboustt on 17/6/2021.
//

#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "../../philo_one.h"

typedef enum e_bool
{
	false = 0,
	true = 1,
}			t_bool;

typedef char * t_string;

int		exit_error(char const *str);
t_bool init(int ac, const char **av);
t_bool	init_data(int ac, const char **av);
t_bool is_valid_str_numeric(const char *arg);
uint64_t get_time();
size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
int			ft_atoi(const char *s);

#endif