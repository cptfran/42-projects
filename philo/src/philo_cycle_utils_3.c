/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:15:19 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/15 16:59:07 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_philo_to_full_if_ate_needed_num_of_meals(t_data *data)
{
	if (data->params->needed_meals != 0
		&& data->philo->num_of_meals == data->params->needed_meals
		&& !data->philo->is_full)
	{
		data->philo->is_full = 1;
		pthread_mutex_lock(&data->params->full_philos_mutex);
		data->params->full_philos++;
		pthread_mutex_unlock(&data->params->full_philos_mutex);
	}
}

long	elapsed_time(struct timeval last_meal_time)
{
	struct timeval	current_time;
	long			elapsed_time_in_microsec;

	if (gettimeofday(&current_time, NULL) != 0)
		return (-1);
	elapsed_time_in_microsec = (current_time.tv_sec * 1000000
			+ current_time.tv_usec)
		- (last_meal_time.tv_sec * 1000000 + last_meal_time.tv_usec);
	return (elapsed_time_in_microsec);
}

long	timestamp(void)
{
	struct timeval	current_time;
	long			time_in_milisec;

	if (gettimeofday(&current_time, NULL) != 0)
		return (-1);
	time_in_milisec = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	if (time_in_milisec < 0)
		return (-2);
	return (time_in_milisec);
}

int	time_to_die_shorter_than_time_to_eat_plus_time_to_sleep(t_data *data)
{
	if (data->params->time_to_die < data->params->time_to_eat
		+ data->params->time_to_sleep)
	{
		usleep(data->params->time_to_die
			- elapsed_time(data->philo->last_meal_time));
		if (time_to_die_passed(data))
			return (1);
	}
	return (0);
}

int	check_death_for_2_philo(t_data *data)
{
	long	time_diff;

	time_diff = (data->params->time_to_die - (data->params->time_to_eat
				+ data->params->time_to_sleep)) / 1000;
	if ((time_diff < 100) && data->params->num_of_philo == 2)
	{
		usleep(time_diff * 1000);
		if (time_to_die_passed(data))
			return (1);
	}
	return (0);
}
