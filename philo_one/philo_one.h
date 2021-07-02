#ifndef PHILO_ONE_H
#define PHILO_ONE_H

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "../philosophers.h"
#include "../utility/utils.h"

#define TO_MICRO_SEC 1000

void lock_and_output(int act, int which);

#endif
