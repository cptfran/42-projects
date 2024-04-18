/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:28:55 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/15 14:31:35 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	get_time_of_last_meal(t_data *data)
{
	if (gettimeofday(&data->philo->last_meal_time, NULL) != 0)
		return ;
}

int	even_philo(t_data *data)
{
	if ((data->philo->id - 1) % 2 != 0)
		return (1);
	return (0);
}

int	all_philos_ate_needed_num_of_meals(t_data *data)
{
	pthread_mutex_lock(&data->params->full_philos_mutex);
	if (data->params->needed_meals != 0
		&& data->params->full_philos == data->params->num_of_philo)
	{
		pthread_mutex_unlock(&data->params->full_philos_mutex);
		free(data);
		return (1);
	}
	pthread_mutex_unlock(&data->params->full_philos_mutex);
	return (0);
}

int	philo_picked_forks_and_thought(t_data *data)
{
	if (data->philo->picked_2_forks && data->philo->has_thought)
		return (1);
	return (0);
}

void	set_order_for_picking_forks(t_data *data)
{
	if (data->philo->id % 2 == 0)
	{
		data->philo->first_fork = data->philo->fork_right;
		data->philo->second_fork = data->philo->fork_left;
	}
	else
	{
		data->philo->first_fork = data->philo->fork_left;
		data->philo->second_fork = data->philo->fork_right;
	}
}
