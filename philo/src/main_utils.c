/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:07:52 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/14 19:44:33 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	cleanup_philo_and_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->params->num_of_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < data->params->num_of_philo)
	{
		pthread_mutex_destroy(data->philo[i].fork_left);
		pthread_mutex_destroy(data->philo[i].fork_right);
		i++;
	}
	pthread_mutex_destroy(&data->params->full_philos_mutex);
}

void	free_memory(t_philo *philo, pthread_mutex_t *mutex)
{
	free(philo);
	philo = NULL;
	free(mutex);
	mutex = NULL;
}
