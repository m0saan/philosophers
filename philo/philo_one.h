#ifndef PHILO_ONE_H
#define PHILO_ONE_H

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "utility/utils.h"

#define TO_MICRO_SEC 1000

uint64_t lock_and_output(int current_philo_index);

#endif
