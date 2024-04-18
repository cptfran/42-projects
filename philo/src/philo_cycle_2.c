/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:20:46 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/15 16:53:41 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_think(t_data *data)
{
	if (check_death_for_2_philo(data))
		return ;
	printf("%ld %d is thinking\n", timestamp(), data->philo->id);
	usleep(1000);
	data->philo->has_slept = 0;
	data->philo->has_thought = 1;
}
