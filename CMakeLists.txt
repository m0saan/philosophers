cmake_minimum_required(VERSION 3.19)
project(_Philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(_Philosophers philo_one/philosophers.c philosophers.h utility/utils.h utility/utils.c utility/init.c philo_one/philo_one.h)

target_link_libraries(_Philosophers ${CMAKE_SOURCE_DIR}/libft/libft.a)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -O0 -g3 -pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")