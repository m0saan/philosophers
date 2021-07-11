cmake_minimum_required(VERSION 3.19)
project(_Philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(_Philosophers philo/philo.c philosophers.h philo/utility/utils.h philo/utility/utils.c
        philo/utility/init.c philo/philo.h philo/utility/ft_isdigit.c philo/utility/ft_strlen.c
        philo/utility/ft_atoi.c philo/controller.c philo/sleep.c philo/eat.c)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -fsanitize=address -Ofast -g3 -pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")