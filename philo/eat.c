#include "philo.h"
#include "utility/utils.h"

void	eat(int left, int right, t_philo *philo)
{
	philo->is_eating = 1;
	out(left, " is eating", 0, philo->state);
	my_usleep(philo->state->time_to_eat);
	philo->total_eat += philo->state->time_to_eat;
	pthread_mutex_unlock(&philo->state->forks[right]);
	pthread_mutex_unlock(&philo->state->forks[left]);
	philo->is_eating = 0;
}
