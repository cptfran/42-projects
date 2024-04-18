/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:58:13 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/15 16:00:37 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	pick_first_fork(t_data *data)
{
	pthread_mutex_lock(data->philo->first_fork);
	printf("%ld %d has taken a fork\n", timestamp(), data->philo->id);
}

void	wait_for_second_fork(t_data *data)
{
	pthread_mutex_unlock(data->philo->first_fork);
	usleep(data->params->time_to_die);
	printf("%ld %d died\n", timestamp(), data->philo->id);
	pthread_mutex_lock(&data->params->philo_death);
	data->params->philo_dead = 1;
	pthread_mutex_unlock(&data->params->philo_death);
}

void	pick_second_fork(t_data *data)
{
	pthread_mutex_lock(data->philo->second_fork);
	printf("%ld %d has taken a fork\n", timestamp(), data->philo->id);
}

int	time_to_die_passed(t_data *data)
{
	if ((elapsed_time(data->philo->last_meal_time)) >= data->params->time_to_die
		&& data->params->philo_dead != 1)
	{
		pthread_mutex_lock(&data->params->philo_death);
		data->params->philo_dead = 1;
		printf("%ld %d died\n", timestamp(), data->philo->id);
		pthread_mutex_unlock(&data->params->philo_death);
		philo_release_forks(data);
		return (1);
	}
	return (0);
}

int	time_to_eat_longer_than_time_to_die(t_data *data)
{
	if (data->params->time_to_die < data->params->time_to_eat)
	{
		usleep(data->params->time_to_die);
		if (time_to_die_passed(data))
			return (1);
	}
	return (0);
}
