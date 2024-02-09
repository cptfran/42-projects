/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:09:36 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/01 15:17:52 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_i	init_i(int top, int bot, int left, int right)
{
	t_i	n_i;

	n_i.t = top;
	n_i.b = bot;
	n_i.l = left;
	n_i.r = right;
	return (n_i);
}

int	not_wall(t_map *map, int side)
{
	if (map->tmp_map[side] != '1' && map->tmp_map[side] != 0)
	{
		map->tmp_map[side] = '1';
		return (1);
	}
	return (0);
}

int	not_wall_or_exit(t_map *map, int side)
{
	if (map->tmp_map[side] != '1' && map->tmp_map[side] != 0
		&&map->tmp_map[side] != 'E')
	{
		map->tmp_map[side] = '1';
		return (1);
	}
	return (0);
}

int	surrounded(t_map *map, t_i i)
{
	if (map->full_map[i.t] == '0' || map->full_map[i.b] == '0'
		|| map->full_map[i.l] == '0' || map->full_map[i.r] == '0'
		|| map->full_map[i.t] == 'C' || map->full_map[i.b] == 'C'
		|| map->full_map[i.l] == 'C' || map->full_map[i.r] == 'C'
		|| map->full_map[i.t] == 'P' || map->full_map[i.b] == 'P'
		|| map->full_map[i.l] == 'P' || map->full_map[i.r] == 'P')
		return (0);
	return (1);
}

void	init_coordinates(t_data *data)
{
	data->map_y = 0;
	data->map->i = 0;
	data->map->line_i = 0;
}
