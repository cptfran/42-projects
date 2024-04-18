/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:23:56 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/15 16:54:50 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_cycle(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	get_time_of_last_meal(data);
	if (even_philo(data))
		printf("%ld %d is thinking\n", timestamp(), data->philo->id);
	while (!data->params->philo_dead && !time_to_die_passed(data))
	{
		if (all_philos_ate_needed_num_of_meals(data))
			return (NULL);
		philo_take_forks(data);
		while (!data->params->philo_dead && philo_picked_forks_and_thought(data)
			&& !time_to_die_passed(data))
		{
			philo_eat(data);
			philo_release_forks(data);
		}
		while (!data->params->philo_dead && data->philo->has_eaten
			&& !time_to_die_passed(data))
			philo_sleep(data);
		while (!data->params->philo_dead && data->philo->has_slept
			&& !time_to_die_passed(data))
			philo_think(data);
	}
	return (free(data), NULL);
}

void	*philo_take_forks(t_data *data)
{
	set_order_for_picking_forks(data);
	pick_first_fork(data);
	if (data->params->num_of_philo == 1)
	{
		wait_for_second_fork(data);
		return (NULL);
	}
	pick_second_fork(data);
	data->philo->picked_2_forks = 1;
	return (NULL);
}

void	philo_eat(t_data *data)
{
	if (time_to_die_passed(data) || time_to_eat_longer_than_time_to_die(data))
		return ;
	get_time_of_last_meal(data);
	printf("%ld %d is eating\n", timestamp(), data->philo->id);
	usleep(data->params->time_to_eat);
	data->philo->num_of_meals++;
	set_philo_to_full_if_ate_needed_num_of_meals(data);
	data->philo->has_thought = 0;
	data->philo->has_eaten = 1;
}

void	philo_release_forks(t_data *data)
{
	if (data->params->num_of_philo > 1)
	{
		pthread_mutex_unlock(data->philo->fork_right);
		pthread_mutex_unlock(data->philo->fork_left);
		data->philo->picked_2_forks = 0;
	}
}

void	philo_sleep(t_data *data)
{
	printf("%ld %d is sleeping\n", timestamp(), data->philo->id);
	if (time_to_die_shorter_than_time_to_eat_plus_time_to_sleep(data))
		return ;
	usleep(data->params->time_to_sleep);
	data->philo->has_eaten = 0;
	data->philo->has_slept = 1;
}
